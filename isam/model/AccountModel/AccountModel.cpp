#include "AccountModel.h"

AccountModel::AccountModel(QObject *parent) :
    BaseItemModel(parent)
{
    m_name = "";
    m_password = "";
    m_type = "general";
    m_loginDateTime = QDateTime::currentDateTime();
}

AccountModel::AccountModel(AccountItem *accountItem, QObject *parent) :
    BaseItemModel(parent)
{
    m_name = accountItem->getName();
    m_password = accountItem->getPassword();
    m_type = accountItem->getType();
    m_loginDateTime = accountItem->getLoginDateTime();
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

QDateTime AccountModel::getLoginDateTime()
{
    return m_loginDateTime;
}

void AccountModel::setLoginDateTime(QDateTime dateTime)
{
    m_loginDateTime = dateTime;
    emit statusChanged();
}

void AccountModel::operator =(const AccountModel& model)
{
    this->m_name = model.m_name;
    this->m_password = model.m_password;
    this->m_type = model.m_type;
    this->m_loginDateTime = model.m_loginDateTime;

    emit statusChanged();
}
