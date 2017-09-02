#include "BaseCommodityModel.h"

BaseCommodityModel::BaseCommodityModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "";
}

BaseCommodityModel::BaseCommodityModel(Commodity *commodity, QObject *parent) :
    BaseItemModel(parent)
{
    this->m_id = commodity->getId();
    this->m_name = commodity->getName();
    this->m_count = commodity->getCount();
    this->m_retailPrice = commodity->getRetailPrice();
}

QString BaseCommodityModel::getId()
{
    return m_id;
}

void BaseCommodityModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString BaseCommodityModel::getName()
{
    return m_name;
}

void BaseCommodityModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

int BaseCommodityModel::getCount()
{
    return m_count;
}

void BaseCommodityModel::setCount(int count)
{
    m_count = count;
    emit statusChanged();
}

float BaseCommodityModel::getRetailPrice()
{
    return m_retailPrice;
}

void BaseCommodityModel::setRetailPrice(float retailprice)
{
    m_retailPrice = retailprice;
    emit statusChanged();
}

void BaseCommodityModel::operator=(const BaseCommodityModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;
    this->m_count = model.m_count;
    this->m_retailPrice = model.m_retailPrice;

    emit statusChanged();
}
