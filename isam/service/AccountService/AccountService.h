#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H
#include "AccountItem.h"
#include "AccountNetworkService.h"
#include <QList>
#include <QObject>
#include <QTimer>

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
    void listChanged();

private slots:
    void getLoginStatus(bool status);
    void save();
    void reload();

private:
    AccountService();
    AccountItem* getAdminAccount() const;
    bool add(QString type, QString name, QString password);
    bool remove(QString account); //remove m_accountList Item
    bool removeAll();
    bool verifyAccountIsValid(QString type, QString name, QString password);
    QList<AccountItem *> verifyAccountListIsValid(QList <AccountItem* > list);
    void modifyConfigFile();

private:
    static AccountService* _instance;
    /*Full account information*/
    QList <AccountItem* > m_accountList;
    /*Here are the accounts that have been logged in*/
    QList <AccountItem* > m_loggedInAccountList;
    AccountNetworkService m_networkService;
    QTimer m_delayInit;
};

#endif // ACCOUNTSERVICE_H
