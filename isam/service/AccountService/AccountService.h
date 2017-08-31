#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H
#include "AccountItem.h"
#include <QList>
#include <QObject>

class AccountService : public QObject
{
    Q_OBJECT
public:
    static AccountService* instance();

private:
    AccountService();

    bool verifyAccount(QString type, QString name, QString password);
    bool add(QString type, QString name, QString password);
    bool removeAll();

private:
    void reload();
    bool verifyAccountIsValid(QString type, QString name, QString password);

private:
    static AccountService* _instance;
    QList <AccountItem* > m_accountList;
};

#endif // ACCOUNTSERVICE_H
