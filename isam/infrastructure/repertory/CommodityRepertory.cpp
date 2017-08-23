#include "CommodityRepertory.h"
#include "JsonListConvertor.h"

#include <QJsonDocument>
#include <QFile>

CommodityRepertory * CommodityRepertory::_instance = NULL;

CommodityRepertory *CommodityRepertory::instance()
{
    if (_instance == NULL) {
        _instance = new CommodityRepertory();
    }
    return _instance;
}

QList<Commodity *> CommodityRepertory::getList()
{
    return m_commodity;
}

Commodity *CommodityRepertory::get(QString id)
{
    for (int i = 0; i < m_commodity.count(); i++) {
        if (m_commodity.at(i)->getId() == id) {
            return m_commodity.at(i);
        }
    }

    return NULL;
}

void CommodityRepertory::add(Commodity *musicBase)
{
    if (musicBase == NULL)
        return;

    musicBase->setId(generateRandomId());
    m_commodity.append(musicBase);
    this->save();
}

void CommodityRepertory::remove(QString id)
{
    for (int i = 0; i < m_commodity.count(); i++) {
        if (m_commodity.at(i)->getId() == id) {
            m_commodity.removeAt(i);
            break;
        }
    }

    this->save();
}

void CommodityRepertory::update(Commodity *musicBase)
{
    if (musicBase == NULL)
        return;

    for (int i = 0; i < m_commodity.count(); i++) {
        Commodity * oldMusicBase = m_commodity.at(i);
        if (oldMusicBase->getId() == musicBase->getId()) {
            delete oldMusicBase;

            m_commodity.replace(i, musicBase);
            break;
        }
    }

    this->save();
}

CommodityRepertory::CommodityRepertory()
{
    reload();
}

void CommodityRepertory::save()
{
    JsonListConvertor<Commodity> convertor;
    QJsonValue jsonValue = convertor.toJson(m_commodity);

    QFile saveFile("save.json");
    saveFile.open(QIODevice::WriteOnly);

    QJsonObject jsonObj;
    jsonObj.insert("musicInfoArray", jsonValue.toArray());

    QJsonDocument saveDoc(jsonObj);
    saveFile.write(saveDoc.toJson());
}

void CommodityRepertory::reload()
{
    QFile saveFile("save.json");
    saveFile.open(QIODevice::ReadOnly);
    QByteArray saveData = saveFile.readAll();

    QJsonDocument saveDoc(QJsonDocument::fromJson(saveData));

    QJsonArray jsonList = saveDoc.object().value("musicInfoArray").toArray();
    JsonListConvertor<Commodity> convertor;
    m_commodity = convertor.toList(jsonList);
}

QString CommodityRepertory::generateRandomId()
{
    int randId = rand();
    for (int i = 0; i < m_commodity.count(); i++)
    {
        Commodity* model = m_commodity.at(i);
        if (model->getId().toInt() == randId)
            return generateRandomId();
    }
    return QString::number(randId);
}
