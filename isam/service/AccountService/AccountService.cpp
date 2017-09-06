#include "AccountService.h"

AccountService * AccountService::_instance = NULL;


AccountService::AccountService()
{
    reload();
}

bool AccountService::loginAccount(QString type, QString name, QString password)
{
    for (int i = 0; i < m_accountList.count(); i++) {
        AccountItem* accountItem = m_accountList.at(i);
        if (accountItem->getType() == type &&
            accountItem->getName() == name &&
            accountItem->getPassword() == password) {
            AccountItem* loggedInaccountItem = new AccountItem(accountItem);
            m_loggedInAccountList.append(loggedInaccountItem);
            emit loggedInAccountListChanged();
            return true;
        }
    }
    return false;
}

QList<AccountItem *> AccountService::getLoggedInAccountList()
{
    return m_loggedInAccountList;
}

bool AccountService::logoutAccount(QString type, QString name)
{
    for (int i = 0; i < this->m_loggedInAccountList.count(); i++) {
        AccountItem* item = m_loggedInAccountList.at(i);
        if (item != NULL && item->getType() == type && item->getName() == name) {
            m_loggedInAccountList.removeAt(i);
            delete item;
            emit loggedInAccountListChanged();
            return true;
        }
    }

    return false;
}

bool AccountService::add(QString type, QString name, QString password)
{
    if (verifyAccountIsValid(type, name, password)) {
        AccountItem* accountItem = new AccountItem();
        accountItem->setType(type);
        accountItem->setName(name);
        accountItem->setPassword(password);
        m_accountList.append(accountItem);
        return true;
    }
    else {
        return false;
    }
}

bool AccountService::removeAll()
{
    while (m_accountList.count()) {
        AccountItem * accountItem = m_accountList.last();
        m_accountList.removeLast();
        delete accountItem;
    }
    return true;
}

void AccountService::reload()
{
    this->add(accountTypeList[0], "123456789@qq.com", "123456");
    this->add(accountTypeList[1], "1001", "123456");
}

bool AccountService::verifyAccountIsValid(QString type, QString name, QString password)
{
    if (name == "" || password == "")
        return false;
    for (int i = 0; i < sizeof(accountTypeList)/sizeof(QString); i++) {
        if (type == accountTypeList[i])
            return true;
    }
    return false;
}

AccountService *AccountService::instance()
{
    if (_instance == NULL) {
        _instance = new AccountService();
    }
    return _instance;
}
