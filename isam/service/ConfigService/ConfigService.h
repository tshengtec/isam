#ifndef CONFIGSERVICE_H
#define CONFIGSERVICE_H

#include <QJsonObject>
#include <QJsonArray>

class ConfigService
{
public:
    ConfigService();
    ConfigService(QString targetFile);

    void setTargetFilePath(QString filePath);
    QJsonObject &jsonObj();
    QString getToken();
    QString getShopNo();
    QString getMacAddr();

public:
    void reload();
    void save();
    void clear();
    void append(QJsonObject jsonObj);

private:
    QJsonObject m_jsonObj;
    QString m_filePath;
};

#endif // CONFIGSERVICE_H
