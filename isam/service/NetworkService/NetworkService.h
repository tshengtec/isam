#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

class NetworkService : public QObject
{
    Q_OBJECT
public:
    NetworkService();
    void getAccountInfo(QString account, QString password, QString type);

    QJsonObject getJsonObjectFromString(const QString jsonString);
    QString getStringFromJsonObject(const QJsonObject& jsonObject);

    QJsonObject getJsonObj();

public slots:
   void finishedSlot(QNetworkReply*);

private:
    QNetworkAccessManager m_manager;
    QJsonObject m_jsonObj;
    int m_errorCode;
    QString m_error;
};

#endif // NETWORKSERVICE_H
