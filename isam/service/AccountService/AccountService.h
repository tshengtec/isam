#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H
#include "AccountItem.h"
#include <QList>
#include <QObject>
const QString accountTypeList[] = {
    "admin", "general"
};

class AccountService : public QObject
{
    Q_OBJECT
public:
    static AccountService* instance();
    bool verifyAccount(QString type, QString name, QString password);
    AccountItem* getLoggedinAdminAccount();
    AccountItem* getLoggedinGeneralAccount();

private:
    AccountService();
    bool add(QString type, QString name, QString password);
    bool removeAll();
    void reload();
    bool verifyAccountIsValid(QString type, QString name, QString password);

private:
    static AccountService* _instance;
    /*Full account information*/
    QList <AccountItem* > m_accountList;
    AccountItem* m_loggedinAdminAccount;
    AccountItem* m_loggedinGeneralAccount;
};

#endif // ACCOUNTSERVICE_H
