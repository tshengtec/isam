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
    bool loginAccount(QString type, QString name, QString password);
    bool logoutAccount(QString type, QString name);
    QList<AccountItem *> getLoggedInAccountList();

signals:
    void loggedInAccountListChanged();

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
    /*Here are the accounts that have been logged in*/
    QList <AccountItem* > m_loggedInAccountList;
};

#endif // ACCOUNTSERVICE_H
