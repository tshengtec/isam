#include "Commodity.h"
#include <QJsonObject>

Commodity::Commodity()
{
    m_id = "";
    m_name = QString::fromUtf8("Undefined");
    m_pathName = "/";
    m_musicName = QString::fromUtf8("Undefined");
}

Commodity::~Commodity()
{

}

void Commodity::fromJson(const QJsonObject data)
{
    m_id = data.value("id").toString();
    m_name = data.value("name").toString();
    m_musicName = data.value("musicName").toString();
    m_pathName = data.value("pathName").toString();
}

QJsonObject Commodity::toJson()
{
    QJsonObject data;
    data.insert("id", getId());
    data.insert("name", getName());
    data.insert("musicName", getMusicName());
    data.insert("pathName", getPathName());

    return data;
}

QString Commodity::getId()
{
    return m_id;
}

void Commodity::setId(QString id)
{
    m_id = id;
}

QString Commodity::getName()
{
    return m_name;
}

void Commodity::setName(QString name)
{
    m_name = name;
}

QString Commodity::getMusicName()
{
    return m_musicName;
}

void Commodity::setMusicName(QString musicName)
{
    m_musicName = musicName;
}

QString Commodity::getPathName()
{
    return m_pathName;
}

void Commodity::setPathName(QString pathName)
{
    m_pathName = pathName;
}
