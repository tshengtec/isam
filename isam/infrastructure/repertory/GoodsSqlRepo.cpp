#include "GoodsSqlRepo.h"
#include "ConfigService.h"
#include "GlobalDefinition.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>

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

    QString insert_sql = "insert into person values (?, ?, ?)";
    m_sqlQuery.prepare(insert_sql);
    m_sqlQuery.addBindValue(jsonObj.value("id").toInt());
    m_sqlQuery.addBindValue(jsonObj.value("categoryName").toString());
    m_sqlQuery.addBindValue(jsonObj.value("goodsName").toString());

    if (!m_sqlQuery.exec()) {
        qDebug()<<"Insert failed!!!(m_sqlQuery.exec())";
        return false;
    }

    return true;
}

QList<QVariantMap> GoodsSqlRepo::getList()
{
    m_sqlQuery.exec("SELECT goodsName FROM Person WHERE goodsName LIKE A%");
}

void GoodsSqlRepo::getGoodsList(QNetworkReply *reply)
{
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
                qDebug()<<"Clear failed!!";
            }
        }

        QJsonArray recordList = goodsJsonObj.value("recordList").toArray();
        for (int i = 0; i < recordList.count(); i++) {
            this->insert(recordList.at(i).toObject());
        }


        if (pageCount >= currentPage) {
            currentPage++;
            m_req.setUrl(QUrl(getUrlStr() + "&pageNum="+ QString::number(currentPage) +"&numPerPage=10"));
            networkAccessManager().get(m_req);
        }
        else {
            bool status = m_sqlQuery.exec("SELECT goodsName FROM person WHERE goodsName LIKE 'A%'");
            qDebug()<<status<<">>>>>>>";
            while(m_sqlQuery.next())
            {

                qDebug() << m_sqlQuery.value("goodsName").toString()<<">>>>";
            }
        }

    }
    else {
    }

    reply->deleteLater();
}

GoodsSqlRepo::GoodsSqlRepo()
{
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        db = QSqlDatabase::database("qt_sql_default_connection");
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE");//添加数据库驱动
        db.setDatabaseName(GOODS_DB_FILE_NAME); //数据库连接命名
    }

    if(!db.open()) //打开数据库
         qDebug("open failed!");
     else
         qDebug("open success!");

     m_sqlQuery = QSqlQuery(db); //以下执行相关QSL语句

     if(!db.tables().contains("person"))
         m_sqlQuery.exec("create table person (id int primary key, categoryName varchar(20), goodsName varchar(20))");

     connect(&networkAccessManager(), SIGNAL(finished(QNetworkReply*)), this, SLOT(getGoodsList(QNetworkReply*)));

     init();
}

void GoodsSqlRepo::init()
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    QString token = configService.getToken();

    m_req.setRawHeader(QByteArray("Token"), QByteArray(token.toStdString().c_str()));
    m_req.setUrl(QUrl(getUrlStr() + "&pageNum=1&numPerPage=10"));

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

QString GoodsSqlRepo::getUrlStr()
{
    QString urlStr = "http://api.cashier.slktea.com/isam-web-cashier" +
            QString(GET_SHOP_GOODS) + "?shopNo" + "=" + this->getShopNo();
    return urlStr;
}
