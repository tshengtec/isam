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

void AccountItem::fromJson(const QJsonObject data)
{
    m_type = data.value("type").toString();
    m_name = data.value("name").toString();
    m_password = data.value("password").toString();
//    m_loginDateTime = data.value("loginDateTime").toString();
}

QJsonObject AccountItem::toJson()
{
    QJsonObject data;
    data.insert("type", getType());
    data.insert("name", getName());
    data.insert("password", getPassword());
//    data.insert("loginDateTime", getLoginDateTime());

    return data;
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
