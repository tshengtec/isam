#include "BaseCommodityModel.h"

BaseCommodityModel::BaseCommodityModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "";
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

void BaseCommodityModel::operator=(const BaseCommodityModel &model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;

    emit statusChanged();
}
