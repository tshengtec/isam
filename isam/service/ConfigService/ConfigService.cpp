#include "ConfigService.h"
#include <QFile>
#include <QJsonDocument>
#include <QNetworkInterface.h>

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

QString ConfigService::getShopNo()
{
    if (m_jsonObj.isEmpty())
        return "";

    QJsonObject loginInfoObj = m_jsonObj.value("loginInfo").toObject();
    if (loginInfoObj.isEmpty())
        return "";

    QJsonArray shops = loginInfoObj.value("shops").toArray();
    if (shops.isEmpty())
        return "";

    QString shopNo = shops.at(0).toObject().value("shopNo").toString();

    return shopNo;
}

QString ConfigService::getMacAddr()
{
    QList<QNetworkInterface> nets = QNetworkInterface::allInterfaces();// 获取所有网络接口列表
    int nCnt = nets.count();
    QString strMacAddr = "";
    for(int i = 0; i < nCnt; i ++)
    {
        // 如果此网络接口被激活并且正在运行并且不是回环地址，则就是我们需要找的Mac地址
        if(nets[i].flags().testFlag(QNetworkInterface::IsUp) && nets[i].flags().testFlag(QNetworkInterface::IsRunning) && !nets[i].flags().testFlag(QNetworkInterface::IsLoopBack))
        {
            strMacAddr = nets[i].hardwareAddress();
            break;
        }
    }
    return strMacAddr;
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
