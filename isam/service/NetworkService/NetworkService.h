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

    QHostInfo networkConnection();
    bool isNetworkConnection();

    QJsonObject getJsonObjectFromString(const QString jsonString);
    QString getStringFromJsonObject(const QJsonObject& jsonObject);

private:
};

#endif // NETWORKSERVICE_H
