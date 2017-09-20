#ifndef ACCOUNTAccountNetworkService_H
#define ACCOUNTAccountNetworkService_H
#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include "NetworkService.h"
#include "AccountNetworkService.h"

class AccountNetworkService : public NetworkService
{
    Q_OBJECT
public:
    AccountNetworkService();
    void getAccountInfo(QString account, QString password, QString type);

    QJsonObject getJsonObj();

signals:
    void returnLoginStatus(bool isSuccess);

public slots:
   void finishedSlot(QNetworkReply*);

private:
    QNetworkAccessManager m_manager;
    QJsonObject m_jsonObj;
    QString m_account;
    QByteArray m_passwordMD5;
    QString m_type;
};

#endif // ACCOUNTAccountNetworkService_H
