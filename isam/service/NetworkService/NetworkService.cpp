#include "NetworkService.h"
#include "AccountService.h"
#include <QJsonDocument>
#include <QDebug>

NetworkService::NetworkService()
{
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

