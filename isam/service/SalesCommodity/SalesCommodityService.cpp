#include "SalesCommodityService.h"
#include "CommodityRepertory.h"
#include "ConfigService.h"
#include "GlobalDefinition.h"

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QNetworkRequest>
#include <QNetworkInterface>
#include <QJsonDocument>

SalesCommodityService * SalesCommodityService::_instance = NULL;


SalesCommodityService::SalesCommodityService()
{
    connect(&m_networkService.networkAccessManager(), SIGNAL(finished(QNetworkReply*)),
                this, SLOT(finishedSlot(QNetworkReply*)));
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
            sales += salesNote->getRealIncome();
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

QJsonArray SalesCommodityService::goodsInfo()
{
    QJsonArray array;
    QList<QVariantMap> goodsList = m_salesNote.getList();

    for (int i = 0; i < goodsList.count(); i++) {
        QJsonObject obj;
        obj.insert("id", goodsList.at(i).value("id").toLongLong());
        obj.insert("quantity", goodsList.at(i).value("quantity").toInt());
        array.append(obj);
    }
    return array;
}

void SalesCommodityService::finishedSlot(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();  // bytes
    QString jsonString = QString::fromUtf8(bytes);

    QJsonObject goodsJsonObj= m_networkService.getJsonObjectFromString(jsonString);
    qDebug()<<goodsJsonObj<<">>>>>";
    if (reply->error() == QNetworkReply::NoError) {

    }
    else {
        qDebug()<<reply->errorString()<<"reply->errorString";
    }

    reply->deleteLater();
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

    this->postSellingCmd();

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

bool SalesCommodityService::postSellingCmd()
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    QString token = configService.getToken();

    QNetworkRequest req;
    req.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");
    req.setRawHeader(QByteArray("Token"), QByteArray(token.toStdString().c_str()));

    QByteArray byteArray;
    byteArray.append("goodsInfo=");
    byteArray.append(QString(QJsonDocument(goodsInfo()).toJson()));

    byteArray.append("&payway=");
    byteArray.append(m_payInfo.value("payway").toString());

    byteArray.append("&shopNo=");
    byteArray.append(configService.getShopNo());

    byteArray.append("&bizNo=");
    byteArray.append(QDateTime::currentDateTime().toTime_t());

    byteArray.append("&authCode=");
    byteArray.append(m_payInfo.value("authCode").toString());

    byteArray.append("&totalFee=");
    byteArray.append(QString("%1").arg(m_salesNote.getRealIncome()));

    byteArray.append("&macAddr=");
    byteArray.append(configService.getMacAddr());

    byteArray.append("&cash=");
    QString cash = QString("%1").arg(m_salesNote.getRealIncome() - m_payInfo.value("paywayTotal").toFloat());
    byteArray.append(cash);

    req.setUrl(QUrl("http://api.cashier.slktea.com/isam-web-cashier" +QString(PUSH_SALES_RECORD)));

    m_networkService.networkAccessManager().post(req, byteArray);
}

void SalesCommodityService::setPayInfo(QVariantMap info)
{
    m_payInfo = info;
}

QVariantMap SalesCommodityService::getPayInfo()
{
    return m_payInfo;
}
