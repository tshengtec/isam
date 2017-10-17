#include "BaseCommodityModel.h"

BaseCommodityModel::BaseCommodityModel(QObject *parent) :
    BaseItemModel(parent)
{
}

BaseCommodityModel::BaseCommodityModel(Commodity *commodity, QObject *parent) :
    BaseItemModel(parent)
{
}

QVariantMap BaseCommodityModel::getMap()
{
    return m_map;
}

void BaseCommodityModel::fromMap(QVariantMap map)
{
    m_map = map;
}

void BaseCommodityModel::operator=(const BaseCommodityModel &model)
{
    m_map = model.m_map;
    emit statusChanged();
}
