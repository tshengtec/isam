#include "AccountNetworkService.h"
#include "AccountService.h"
#include <QJsonDocument>
#include <QDebug>

AccountNetworkService::AccountNetworkService()
{
    connect(&m_manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));
}

void AccountNetworkService::getAccountInfo(QString account, QString password, QString type)
{
    m_account = account;
    m_type = type;
    m_passwordMD5 = QCryptographicHash::hash(password.toLatin1(), QCryptographicHash::Md5);

    QString url = "";
    if (m_type == accountTypeList[0]) {
        url = "http://api.erp.slktea.com/isam-web-merchant/auth?"
              "account=" + m_account +"&password=" + m_passwordMD5.toHex();

    }
    else if (m_type == accountTypeList[1]) {
        url = "http://api.cashier.slktea.com/isam-web-cashier/auth?"
              "account=" + m_account +"&password=" + m_passwordMD5.toHex();
    }

    m_manager.get(QNetworkRequest(QUrl(url)));
}

void AccountNetworkService::finishedSlot(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();  // bytes
    QString jsonString = QString::fromUtf8(bytes);
    m_jsonObj = this->getJsonObjectFromString(jsonString);

    if (reply->error() == QNetworkReply::NoError)
    {
        m_jsonObj.insert("passwordMD5", QString(m_passwordMD5.toHex()));
        m_jsonObj.insert("type", m_type);
        emit returnLoginStatus(true);
    }
    else {
        emit returnLoginStatus(false);
    }

    reply->deleteLater();
}

QJsonObject AccountNetworkService::getJsonObj()
{
    return m_jsonObj;
}
