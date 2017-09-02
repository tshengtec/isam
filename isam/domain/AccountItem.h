#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H
#include <QString>
#include <QDateTime>

class AccountItem
{
public:
    AccountItem();
    AccountItem(AccountItem* accountItem);

    /*type ==> "admin", "general"*/
    QString getType();
    void setType(QString type);

    QString getName();
    void setName(QString name);

    QString getPassword();
    void setPassword(QString password);

    QDateTime getLoginDateTime();
    void setLoginDateTime(QDateTime dateTime);

private:
    QString m_type;
    QString m_name;
    QString m_password;
    QDateTime m_loginDateTime;
};

#endif // ACCOUNTITEM_H
