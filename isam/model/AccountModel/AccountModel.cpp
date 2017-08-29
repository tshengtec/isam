#include "AccountModel.h"

AccountModel::AccountModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_id = "";
    m_name = "";
    m_password = "";
    m_type = "general";
}

QString AccountModel::getId()
{
    return m_id;
}

void AccountModel::setId(QString id)
{
    m_id = id;
    emit statusChanged();
}

QString AccountModel::getName()
{
    return m_name;
}

void AccountModel::setName(QString name)
{
    m_name = name;
    emit statusChanged();
}

QString AccountModel::getPassword()
{
    return m_password;
}

void AccountModel::setPassword(QString password)
{
    m_password = password;
    emit statusChanged();
}

void AccountModel::operator =(const AccountModel& model)
{
    this->m_id = model.m_id;
    this->m_name = model.m_name;
    this->m_password = model.m_password;
    this->m_type = model.m_type;

    emit statusChanged();
}
