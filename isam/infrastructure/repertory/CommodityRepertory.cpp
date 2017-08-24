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

void CommodityRepertory::add(Commodity *commodity)
{
    if (commodity == NULL)
        return;

    commodity->setId(generateRandomId());
    m_commodity.append(commodity);
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

void CommodityRepertory::update(Commodity *commodity)
{
    if (commodity == NULL)
        return;

    for (int i = 0; i < m_commodity.count(); i++) {
        Commodity * oldCommodity = m_commodity.at(i);
        if (oldCommodity->getId() == commodity->getId()) {
            delete oldCommodity;

            m_commodity.replace(i, commodity);
            break;
        }
    }

    this->save();
}

CommodityRepertory::CommodityRepertory()
{
    reload();
//    Commodity* commdity1 = new Commodity();
//    commdity1->setId("2893849123");
//    commdity1->setName("铅笔");

//    add(commdity1);
//    Commodity* commdity2 = new Commodity();
//    commdity2->setId("8928123728");
//    commdity2->setName("钢笔");
//    add(commdity1);
}

void CommodityRepertory::save()
{
    JsonListConvertor<Commodity> convertor;
    QJsonValue jsonValue = convertor.toJson(m_commodity);

    QFile saveFile("save.json");
    saveFile.open(QIODevice::WriteOnly);

    QJsonObject jsonObj;
    jsonObj.insert("commodityInfoArray", jsonValue.toArray());

    QJsonDocument saveDoc(jsonObj);
    saveFile.write(saveDoc.toJson());
}

void CommodityRepertory::reload()
{
    QFile saveFile("save.json");
    saveFile.open(QIODevice::ReadOnly);
    QByteArray saveData = saveFile.readAll();

    QJsonDocument saveDoc(QJsonDocument::fromJson(saveData));

    QJsonArray jsonList = saveDoc.object().value("commodityInfoArray").toArray();
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
