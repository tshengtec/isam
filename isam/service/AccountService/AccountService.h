#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H
#include "AccountItem.h"
#include <QList>
#include <QObject>
const QString accountTypeList[] = {
    "admin", "geneal"
};

class AccountService : public QObject
{
    Q_OBJECT
public:
    static AccountService* instance();
    bool verifyAccount(QString type, QString name, QString password);

private:
    AccountService();
    bool add(QString type, QString name, QString password);
    bool removeAll();
    void reload();
    bool verifyAccountIsValid(QString type, QString name, QString password);

private:
    static AccountService* _instance;
    QList <AccountItem* > m_accountList;
};

#endif // ACCOUNTSERVICE_H
