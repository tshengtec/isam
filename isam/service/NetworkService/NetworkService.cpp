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
    QByteArray bytes = reply->readAll();  // bytes
    QString jsonString = QString::fromUtf8(bytes);
    m_jsonObj = this->getJsonObjectFromString(jsonString);

    if (reply->error() == QNetworkReply::NoError)
    {
        m_errorCode = 0;
        m_error = "";
    }
    else {
        m_errorCode = m_jsonObj.value("code").toInt();
        m_error = m_jsonObj.value("error").toString();
    }

    reply->deleteLater();
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
