#include "SalesCommodityService.h"
#include "CommodityRepertory.h"
#include "ConfigService.h"
#include "GlobalDefinition.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QNetworkRequest>
#include <QNetworkInterface>

SalesCommodityService * SalesCommodityService::_instance = NULL;


SalesCommodityService::SalesCommodityService()
{
}

SalesCommodityService *SalesCommodityService::instance()
{
    if (_instance == NULL) {
        _instance = new SalesCommodityService();
    }
    return _instance;
}

SalesNote SalesCommodityService::getSalesNote()
{
    return m_salesNote;
}

SalesNote SalesCommodityService::getPendingSalesNote()
{
    return m_pendingSalesNote;
}

QList<SalesNote *> SalesCommodityService::getSalesList()
{
    return m_SalesList;
}

float SalesCommodityService::getSales()
{
    float sales = 0;
    for (int i = 0; i < m_SalesList.count(); i++) {
        SalesNote* salesNote = m_SalesList.at(i);
        for (int j = 0; salesNote != NULL && j < salesNote->getList().count(); j++) {
            QVariantMap commodity = salesNote->getList().at(j);
            sales = 0;
            //sales += commodity->getRetailPrice()*commodity->getCount();
        }
    }
    return sales;
}

SalesNote *SalesCommodityService::copySalesNote(SalesNote *salesNote)
{
    SalesNote *newSalesNote = new SalesNote(salesNote);
    return newSalesNote;
}

void SalesCommodityService::removeSalesNote(SalesNote *salesNote)
{
    delete salesNote;
    salesNote = NULL;
}

QVariantMap SalesCommodityService::get(QString id)
{
    QVariantMap commodity = m_salesNote.get(id);
    return commodity;
}

bool SalesCommodityService::add(QString id)
{
    bool isSuccess = m_salesNote.add(id);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::remove(QString id)
{
    bool isSuccess = m_salesNote.remove(id);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::update(QVariantMap commodity)
{
    bool isSuccess = m_salesNote.update(commodity);
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::removeAll()
{
    bool isSuccess = m_salesNote.removeAll();
    if (isSuccess)
        emit listChanged();
    return isSuccess;
}

bool SalesCommodityService::settleMent()
{
    SalesNote* salesNote = new SalesNote();
    salesNote->setDateTime(QDateTime::currentDateTime());
    salesNote->setList(this->m_salesNote.copyMyselfList());
    m_SalesList.append(salesNote);
    this->removeAll();
    return true;
}

QString SalesCommodityService::onPendingOperation()
{
    if (m_salesNote.getList().count() == 0)
        return "挂单失败，没有商品！";
    if (m_pendingSalesNote.getList().count() != 0)
        return "挂单失败，<取单>未取走";

    m_pendingSalesNote.setList(m_salesNote.copyMyselfList());
    m_salesNote.removeAll();
    emit listChanged();
    return "挂单成功";
}

QString SalesCommodityService::onGettingOperation()
{
    if (m_pendingSalesNote.getList().count() == 0)
        return "取单失败，<取单>没有商品！";
    if (m_salesNote.getList().count() != 0)
        return "取单失败，请先结算当前商品！";


    m_salesNote.setList(m_pendingSalesNote.copyMyselfList());
    m_pendingSalesNote.removeAll();
    emit listChanged();
    return "取单成功";
}

bool SalesCommodityService::postSellingDoc()
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
//    byteArray.append(this->getShopNo().toStdString().c_str());
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
}
