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

    QJsonObject getJsonObjectFromString(const QString jsonString);
    QString getStringFromJsonObject(const QJsonObject& jsonObject);

private:
};

#endif // NETWORKSERVICE_H
