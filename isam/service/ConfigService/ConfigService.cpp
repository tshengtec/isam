#include "ConfigService.h"
#include <QFile>
#include <QJsonDocument>

ConfigService::ConfigService()
{
    /*Default*/
    m_filePath = "config.json";
    this->reload();
}

ConfigService::ConfigService(QString targetFile)
{
    m_filePath = targetFile;
    this->reload();
}

void ConfigService::setTargetFilePath(QString filePath)
{
       m_filePath = filePath;
       this->reload();
}

QJsonObject &ConfigService::jsonObj()
{
    return m_jsonObj;
}

QString ConfigService::getToken()
{
    if (m_jsonObj.isEmpty())
        return "";

    QJsonObject loginInfoObj = m_jsonObj.value("loginInfo").toObject();
    if (loginInfoObj.isEmpty())
        return "";

    QString token = loginInfoObj.value("accessToken").toString();
    return token;
}

void ConfigService::reload()
{
    QFile configFile(m_filePath);
    configFile.open(QIODevice::ReadOnly);
    QByteArray saveData = configFile.readAll();

    QJsonDocument saveDoc(QJsonDocument::fromJson(saveData));

    m_jsonObj = saveDoc.object();
}

void ConfigService::save()
{
    QFile configFile(m_filePath);
    configFile.open(QIODevice::ReadWrite);

    configFile.resize(0);
    configFile.write(QJsonDocument(this->jsonObj()).toJson());
    configFile.close();
}

void ConfigService::clear()
{
    QFile configFile(m_filePath);

    configFile.open(QIODevice::ReadWrite);
    configFile.resize(0);
    configFile.close();
}

void ConfigService::append(QJsonObject jsonObj)
{
    QFile configFile(m_filePath);

    configFile.open(QIODevice::ReadWrite);
    configFile.write(QJsonDocument(jsonObj).toJson());
    configFile.close();
}
