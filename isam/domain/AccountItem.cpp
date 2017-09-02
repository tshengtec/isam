#include "AccountItem.h"

AccountItem::AccountItem()
{
    m_type = "";
    m_name = "";
    m_password = "";
    m_loginDateTime = QDateTime::currentDateTime();
}

AccountItem::AccountItem(AccountItem *accountItem)
{
    m_type = accountItem->getType();
    m_name = accountItem->getName();
    m_password = accountItem->getPassword();
    m_loginDateTime = accountItem->getLoginDateTime();
}

QString AccountItem::getType()
{
    return m_type;
}

void AccountItem::setType(QString type)
{
    m_type = type;
}

QString AccountItem::getName()
{
    return m_name;
}

void AccountItem::setName(QString name)
{
    m_name = name;
}

QString AccountItem::getPassword()
{
    return m_password;
}

void AccountItem::setPassword(QString password)
{
    m_password = password;
}

QDateTime AccountItem::getLoginDateTime()
{
    return m_loginDateTime;
}

void AccountItem::setLoginDateTime(QDateTime dateTime)
{
    m_loginDateTime = dateTime;
}
