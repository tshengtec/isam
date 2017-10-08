#include "CommodityCategoryNetworkService.h"
#include "ConfigService.h"
#include "GlobalDefinition.h"

CommodityCategoryNetworkService::CommodityCategoryNetworkService()
{
    ConfigService configService = ConfigService(QString(CONFIG_JSON_FILE_NAME));
    QString token = configService.getToken();

    QNetworkRequest* req = new QNetworkRequest();
    req->setRawHeader(QByteArray("Token"), QByteArray(token.toStdString().c_str()));

    req->setUrl(QUrl(getUrlStr() + "&pageNum=1&numPerPage=10"));
    networkAccessManager().get(*req);

    connect(&networkAccessManager(), SIGNAL(finished(QNetworkReply*)), this, SLOT(getCommodityCategoryList(QNetworkReply*)));
}

void CommodityCategoryNetworkService::getCommodityCategoryList(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        ConfigService goods = ConfigService(QString(GOODS_JSON_FILE_NAME));

        QByteArray bytes = reply->readAll();  // bytes
        QString jsonString = QString::fromUtf8(bytes);

        goods.jsonObj() =  this->getJsonObjectFromString(jsonString);
        if (goods.jsonObj().isEmpty())
            return;

        if (goods.jsonObj().value("currentPage").toInt() == 1) {
            goods.clear();
        }

        goods.append(goods.jsonObj());
    }
    else {
    }

    reply->deleteLater();
}

QString CommodityCategoryNetworkService::getShopNo()
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

QString CommodityCategoryNetworkService::getUrlStr()
{
    QString urlStr = "http://api.cashier.slktea.com/isam-web-cashier" +
            QString(GET_SHOP_GOODS) + "?shopNo" + "=" + this->getShopNo();
    return urlStr;
}
