#include "NetworkService.h"
#include "AccountService.h"
#include <QJsonDocument>
#include <QDebug>

NetworkService::NetworkService()
{
    connect(&m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
}

void NetworkService::getAccountInfo(QString account, QString password, QString type)
{
    QString url = "";
    QByteArray passwordMD5 = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5);

    if (type == accountTypeList[0]) {
        url = "http://api.erp.slktea.com/isam-web-merchant/auth?"
              "account=" + account +"&password=" + passwordMD5.toHex();

    }
    else if (type == accountTypeList[1]) {
        url = "http://api.cashier.slktea.com/isam-web-cashier/auth?"
              "account=" + account +"&password=" + passwordMD5.toHex();
    }

    m_manager.get(QNetworkRequest(QUrl(url)));
}

void NetworkService::finishedSlot(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();  // bytes
        QString jsonString = QString::fromUtf8(bytes);
        QJsonObject jsonObje = this->getJsonObjectFromString(jsonString);
        qDebug()<<jsonObje;
    }
    else {
        QByteArray bytes = reply->readAll();  // bytes
        QString jsonString = QString::fromUtf8(bytes);
        QJsonObject jsonObje = this->getJsonObjectFromString(jsonString);
        qDebug()<<jsonObje;
    }

    reply->deleteLater();
}

/*QString -> QJsonObject*/
QJsonObject NetworkService::getJsonObjectFromString(const QString jsonString){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toLocal8Bit().data());
    if( jsonDocument.isNull() ){
        qDebug()<< "Format error!"<< jsonString.toLocal8Bit().data();
    }
    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}

/*QJsonObject -> QString*/
QString NetworkService::getStringFromJsonObject(const QJsonObject& jsonObject){
    return QString(QJsonDocument(jsonObject).toJson());
}
