#ifndef ACCOUNTITEM_H
#define ACCOUNTITEM_H
#include <QString>

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

private:
    QString m_type;
    QString m_name;
    QString m_password;
};

#endif // ACCOUNTITEM_H
