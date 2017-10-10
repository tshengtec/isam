#include "Commodity.h"
#include "GlobalDefinition.h"
#include <QJsonObject>

Commodity::Commodity()
{
    m_id = "";
    m_name = QString::fromUtf8("Undefined");
    m_count = 0;
    m_retailPrice = 0;
    m_commodityType = "";
}

Commodity::Commodity(Commodity *commodity)
{
    if (commodity == NULL) return;
    this->m_id = commodity->m_id;
    this->m_name = commodity->m_name;
    this->m_count = commodity->m_count;
    this->m_retailPrice = commodity->m_retailPrice;
}

Commodity::Commodity(Commodity& commodity)
{

}

Commodity::~Commodity()
{

}

void Commodity::fromJson(const QJsonObject data)
{
    m_id = data.value("id").toString();
    m_name = data.value("name").toString();
    m_count = data.value("count").toInt();
    m_retailPrice = data.value("retailPrice").toInt();
}

QJsonObject Commodity::toJson()
{
    QJsonObject data;
    data.insert("id", getId());
    data.insert("name", getName());
    data.insert("count", getRetailPrice());
    data.insert("retailPrice", getCount());

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

float Commodity::getRetailPrice()
{
    return m_retailPrice;
}

void Commodity::setRetailPrice(float retaliPrice)
{
    m_retailPrice = retaliPrice;
}

QString Commodity::getCommodityType()
{
    return m_commodityType;
}

void Commodity::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
}

void Commodity::fromMap(QVariantMap map)
{
    m_id = map["barCode"].toString();
    m_name = map["goodsName"].toString();
}

int Commodity::getCount()
{
    return m_count;
}

void Commodity::setCount(int count)
{
    m_count = count;
}
