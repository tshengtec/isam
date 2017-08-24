#include "CommodityModel.h"

CommodityModel::CommodityModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "";
}

QString CommodityModel::getId()
{
    return m_id;
}

void CommodityModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString CommodityModel::getName()
{
    return m_name;
}

void CommodityModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

void CommodityModel::operator=(const CommodityModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;

    emit statusChanged();
}
