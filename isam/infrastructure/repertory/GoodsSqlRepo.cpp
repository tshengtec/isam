#include "GoodsSqlRepo.h"
#include "ConfigService.h"
#include "GlobalDefinition.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QNetworkInterface>
#include <QDebug>
#include <QFile>

GoodsSqlRepo * GoodsSqlRepo::_instance = NULL;

GoodsSqlRepo *GoodsSqlRepo::instance()
{
    if (_instance == NULL) {
        _instance = new GoodsSqlRepo();
    }
    return _instance;
}

bool GoodsSqlRepo::insert(QJsonObject jsonObj)
{
    if (jsonObj.isEmpty()) {
        qDebug()<<"Insert failed!!!(jsonObj is empty.)";
        return false;
    }
    qDebug()<<jsonObj<<">>>>>>>>>>>>>>>>>>>>>>>>>>>>>";
    QString insert_sql = "insert into person values (?, ?, ?, ?, ?," \
                                                                      "?, ?, ?, ?, ?," \
                                                                      "?, ?, ?, ?, ?," \
                                                                      "?, ?, ?, ?" \
                                 ")";
    m_sqlQuery.prepare(insert_sql);

    for (int i = 0; i < (sizeof(goodsFields)/sizeof(goodsFields[0])); i++) {
        if (goodsFieldsType[i] == "int")
            m_sqlQuery.addBindValue(jsonObj.value(goodsFields[i]).toVariant().toLongLong());
        else
            m_sqlQuery.addBindValue(jsonObj.value(goodsFields[i]));
    }

    if (!m_sqlQuery.exec()) {
        qDebug()<<m_sqlQuery.lastError()<<"Insert failed!!!(m_sqlQuery.exec())";
        return false;
    }
    return true;
}

QList<QVariantMap> GoodsSqlRepo::getList()
{
    m_sqlQuery.exec("SELECT * FROM person WHERE goodsName, barCode LIKE %%");
}

QList<QVariantMap> GoodsSqlRepo::getList(QString target, int page, int pageNum)
{
    int success =true;

    success = m_sqlQuery.exec("SELECT * FROM person WHERE goodsName LIKE '%"+ target +"%' OR barCode LIKE '%"+ target +"%'");
    m_sqlQuery.seek(page-2);
    if (!success)
        qDebug()<<m_sqlQuery.lastError()<<"Select";

    QList<QVariantMap> newList;
    while(m_sqlQuery.next() && (pageNum--)) {
        QVariantMap map;
        for (int i = 0; i < (sizeof(goodsFields)/sizeof(goodsFields[0])); i++) {
            map.insert(goodsFields[i], m_sqlQuery.value(goodsFields[i]));
        }
        newList.append(map);
    }

    return newList;
}

void GoodsSqlRepo::getGoodsList(QNetworkReply *reply)
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    QString token = configService.getToken();

    QNetworkRequest req;
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    req.setRawHeader(QByteArray("Token"), QByteArray(token.toStdString().c_str()));
    qDebug()<<"Token??????????????????????"<<token;
    QByteArray byteArray;
    byteArray.append("goodsInfo=[{id: 11, quantity: 1}]&payway=cash");
    byteArray.append("&shopNo=");
    byteArray.append(this->getShopNo().toStdString().c_str());
    byteArray.append("&bizNo=1507425386000");
    byteArray.append("&authCode=6908512208723");
    byteArray.append("&totalFee=10");

    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }

    byteArray.append("&macAddr=");
    byteArray.append(strMacAddr);
    byteArray.append("&cash=10");
    req.setUrl(QUrl("http://api.cashier.slktea.com/isam-web-cashier" +QString(PUSH_SALES_RECORD)));

//    networkAccessManager().post(req, byteArray);

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray bytes = reply->readAll();  // bytes
        QString jsonString = QString::fromUtf8(bytes);

        QJsonObject goodsJsonObj=  this->getJsonObjectFromString(jsonString);

        if (goodsJsonObj.isEmpty())
            return;

        int pageCount = goodsJsonObj.value("pageCount").toInt();
        int currentPage = goodsJsonObj.value("currentPage").toInt();


        if (currentPage == 1) {
            QString clear_sql = "delete from person";
            m_sqlQuery.prepare(clear_sql);
            if(!m_sqlQuery.exec()) {
                qDebug()<<m_sqlQuery.lastError()<<"delete from person";
            }
        }

        QJsonArray recordList = goodsJsonObj.value("recordList").toArray();
        for (int i = 0; i < recordList.count(); i++) {
            this->insert( this->filterJsonObj(recordList.at(i).toObject()) );
        }


        if (pageCount >= currentPage) {
            currentPage++;
            m_req.setUrl(QUrl(getUrlStr(GET_SHOP_GOODS) + "&pageNum="+ QString::number(currentPage) +"&numPerPage=10"));
            networkAccessManager().get(m_req);
        }
        else {
        }

    }
    else {
    }

    reply->deleteLater();
}

GoodsSqlRepo::GoodsSqlRepo()
{        
    if (QSqlDatabase::contains(GOODS_DB_FILE_NAME))
    {
        m_db = QSqlDatabase::database(GOODS_DB_FILE_NAME);
        qDebug()<<"Exist GOODS_DB_FILE_NAME!";
    }
    else {
        m_db = QSqlDatabase::addDatabase("QSQLITE", GOODS_DB_FILE_NAME);//添加数据库驱动
        m_db.setDatabaseName(GOODS_DB_FILE_NAME); //数据库连接命名
        qDebug()<<"UnExist GOODS_DB_FILE_NAME!";
    }

    if(!m_db.open()) { //打开数据库
         qDebug()<<"open failed!"<<m_db.lastError();
    }
    else {
         qDebug()<<"open success!"<<m_db.lastError();
         QFile file(GOODS_DB_FILE_NAME);
         qDebug()<<GOODS_DB_FILE_NAME<<"<Status>:"<<file.exists();
    }

     m_sqlQuery = QSqlQuery(m_db); //以下执行相关QSL语句

     if(!m_db.tables().contains("person")) {
         if (!m_sqlQuery.exec(QString(CREATE_DB_TABLE)) )
             qDebug()<<m_sqlQuery.lastError()<<CREATE_DB_TABLE;
     }
     else {
         qDebug()<<"Exist table <person>!";
     }
     connect(&networkAccessManager(), SIGNAL(finished(QNetworkReply*)), this, SLOT(getGoodsList(QNetworkReply*)));

     this->update();
}

void GoodsSqlRepo::update()
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    QString token = configService.getToken();

    m_req.setRawHeader(QByteArray("Token"), QByteArray(token.toStdString().c_str()));
    m_req.setUrl(QUrl(getUrlStr(GET_SHOP_GOODS) + "&pageNum=1&numPerPage=10"));

    networkAccessManager().get(m_req);
}

QString GoodsSqlRepo::getShopNo()
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    if (configService.jsonObj().isEmpty())
        return "";

    QJsonObject jsonObj = configService.jsonObj().value("loginInfo").toObject();
    if (jsonObj.isEmpty())
        return "";

    QJsonArray shops = jsonObj.value("shops").toArray();
    if (shops.isEmpty())
        return "";

    //Default
    QString shopNo = shops.at(0).toObject().value("shopNo").toString();

    return shopNo;
}

QString GoodsSqlRepo::getUrlStr(QString str)
{
    QString urlStr = "http://api.cashier.slktea.com/isam-web-cashier" +
            QString(str) + "?shopNo" + "=" + this->getShopNo();
    return urlStr;
}

QJsonObject GoodsSqlRepo::filterJsonObj(QJsonObject target)
{
    QJsonObject newJsonObj;

    QJsonObject::Iterator it;
    for (it = target.begin(); it != target.end(); it++) {
        if ( !it.value().isObject() ) {
            newJsonObj.insert(it.key(), it.value());
        }
        else {
            QJsonObject tempObj = it.value().toObject();
            QJsonObject::Iterator subIt;
            for (subIt = tempObj.begin(); subIt != tempObj.end(); subIt++) {
                newJsonObj.insert(subIt.key(), subIt.value());
            }
        }
    }

    return newJsonObj;
}
