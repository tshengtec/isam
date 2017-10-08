#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QHostInfo>

class NetworkService : public QObject
{
    Q_OBJECT
public:
    NetworkService();

    QNetworkAccessManager& networkAccessManager();

    QHostInfo networkConnection();
    bool isNetworkConnection();

    QJsonObject getJsonObjectFromString(const QString jsonString);
    QString getStringFromJsonObject(const QJsonObject& jsonObject);

private:
    QNetworkAccessManager m_manager;
};

#endif // NETWORKSERVICE_H
