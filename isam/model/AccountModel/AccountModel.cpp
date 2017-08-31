#include "AccountModel.h"

AccountModel::AccountModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_isAdminLogged = false;
    m_isGeneralLoged = false;
    m_name = "";
    m_password = "";
    m_type = "general";
}

bool AccountModel::verifyAccount(QString type, QString name, QString password)
{
    return AccountService::instance()->verifyAccount(type, name, password);
}

bool AccountModel::getIsAdminLogged()
{
    return m_isAdminLogged;
}

void AccountModel::setIsAdminLogged(bool status)
{
    m_isAdminLogged = status;
    emit statusChanged();
}

bool AccountModel::getIsGeneralLogged()
{
    return m_isGeneralLoged;
}

void AccountModel::setIsGeneralLogged(bool status)
{
    m_isGeneralLoged = status;
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

QString AccountModel::getType()
{
    return m_type;
}

void AccountModel::setType(QString type)
{
    m_type = type;
    emit statusChanged();
}

void AccountModel::operator =(const AccountModel& model)
{
    this->m_isAdminLogged = model.m_isAdminLogged;
    this->m_isGeneralLoged = model.m_isGeneralLoged;
    this->m_name = model.m_name;
    this->m_password = model.m_password;
    this->m_type = model.m_type;

    emit statusChanged();
}
