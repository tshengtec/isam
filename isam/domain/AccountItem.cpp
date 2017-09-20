#include "AccountItem.h"

AccountItem::AccountItem()
{
    m_type = "";
    m_name = "";
    m_password = "";
    m_passwordMD5 = "";
    m_loginDateTime = QDateTime::currentDateTime();
}

AccountItem::AccountItem(const QJsonObject jsonObj)
{
    fromJson(jsonObj);
}

AccountItem::AccountItem(AccountItem *accountItem)
{
    m_type = accountItem->getType();
    m_name = accountItem->getName();
    m_password = accountItem->getPassword();
    m_passwordMD5 = accountItem->getPasswordMD5();
    m_loginDateTime = accountItem->getLoginDateTime();
}

void AccountItem::fromJson(const QJsonObject data)
{
    m_type = data.value("type").toString();
    m_name = data.value("account").toString();
    m_passwordMD5 = data.value("passwordMD5").toString();
//    m_loginDateTime = getDateTimefromJsonArray(data.value("shops").toArray());
}

QJsonObject AccountItem::toJson()
{
    QJsonObject data;
    data.insert("type", getType());
    data.insert("account", getName());
    data.insert("passwordMD5", getPasswordMD5());
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

QString AccountItem::getPasswordMD5()
{
    return m_passwordMD5;
}

void AccountItem::setPasswordMD5(QString password)
{
    m_passwordMD5 = password;
}

QDateTime AccountItem::getLoginDateTime()
{
    return m_loginDateTime;
}

void AccountItem::setLoginDateTime(QDateTime dateTime)
{
    m_loginDateTime = dateTime;
}

QDateTime AccountItem::getDateTimefromJsonArray(QJsonArray jsonArray)
{

}
