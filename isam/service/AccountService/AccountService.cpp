#include "AccountService.h"

AccountService * AccountService::_instance = NULL;


AccountService::AccountService()
{
    reload();
    m_loggedinAdminAccount = new AccountItem();
    m_loggedinGeneralAccount = new AccountItem();
}

bool AccountService::verifyAccount(QString type, QString name, QString password)
{
    for (int i = 0; i < m_accountList.count(); i++) {
        AccountItem* accountItem = m_accountList.at(i);
        if (accountItem->getType() == type &&
            accountItem->getName() == name &&
            accountItem->getPassword() == password) {
            if (type == accountTypeList[0]) {
                m_loggedinAdminAccount->setType(type);
                m_loggedinAdminAccount->setName(name);
                m_loggedinAdminAccount->setPassword(password);
            }
            else if (type == accountTypeList[1]) {
                m_loggedinGeneralAccount->setType(type);
                m_loggedinGeneralAccount->setName(name);
                m_loggedinGeneralAccount->setPassword(password);
            }

            return true;
        }
    }
    return false;
}

AccountItem* AccountService::getLoggedinAdminAccount()
{
    if (verifyAccountIsValid(m_loggedinAdminAccount->getType(),
                             m_loggedinAdminAccount->getName(),
                             m_loggedinAdminAccount->getPassword()))
        return NULL;
    else
        return m_loggedinAdminAccount;
}

AccountItem* AccountService::getLoggedinGeneralAccount()
{
    if (verifyAccountIsValid(m_loggedinGeneralAccount->getType(),
                             m_loggedinGeneralAccount->getName(),
                             m_loggedinGeneralAccount->getPassword()))
        return NULL;
    else
        return m_loggedinGeneralAccount;
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
