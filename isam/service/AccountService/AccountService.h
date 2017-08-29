#ifndef ACCOUNTSERVICE_H
#define ACCOUNTSERVICE_H

#include <QAbstractItemModel>

class AccountService : public QObject
{
    Q_OBJECT
public:
    static AccountService* instance();

private:
    AccountService();

private:
    static AccountService* _instance;
};

#endif // ACCOUNTSERVICE_H
