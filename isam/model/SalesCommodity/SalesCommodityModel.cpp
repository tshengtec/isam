#include "SalesCommodityModel.h"

SalesCommodityModel::SalesCommodityModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "";
}

QString SalesCommodityModel::getId()
{
    return m_id;
}

void SalesCommodityModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString SalesCommodityModel::getName()
{
    return m_name;
}

void SalesCommodityModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

void SalesCommodityModel::operator=(const SalesCommodityModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;

    emit statusChanged();
}
