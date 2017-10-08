#include "NetworkService.h"
#include "AccountService.h"
#include <QJsonDocument>
#include <QDebug>

NetworkService::NetworkService()
{
}

QNetworkAccessManager &NetworkService::networkAccessManager()
{
    return m_manager;
}

QHostInfo NetworkService::networkConnection()
{
    QHostInfo info = QHostInfo::fromName("www.baidu.com");
    return info;
}

bool NetworkService::isNetworkConnection()
{
    QHostInfo info = QHostInfo::fromName("www.baidu.com");
    if (info.error() == QHostInfo::NoError)
        return true;
    else
        return false;
}

/*QString -> QJsonObject*/
QJsonObject NetworkService::getJsonObjectFromString(const QString jsonString){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toUtf8().data());
    if( jsonDocument.isNull() ){
        qDebug()<< "Format error!"<< jsonString.toUtf8().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

/*QJsonObject -> QString*/
QString NetworkService::getStringFromJsonObject(const QJsonObject& jsonObject){
    return QString(QJsonDocument(jsonObject).toJson());
}

