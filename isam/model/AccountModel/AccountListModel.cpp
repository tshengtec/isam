#include "AccountListModel.h"
#include "AccountService.h"

AccountListModel::AccountListModel()
{
    m_isAdminLogged = false;
    m_isGeneralLoged = false;
    connect(AccountService::instance(), SIGNAL(loggedInAccountListChanged()), this, SLOT(reload()));
}

bool AccountListModel::loginAccount(QString type, QString name, QString password)
{
    return AccountService::instance()->loginAccount(type, name, password);
}

bool AccountListModel::getIsAdminLogged()
{
    return m_isAdminLogged;
}

void AccountListModel::setIsAdminLogged(bool status)
{
    m_isAdminLogged = status;
    emit statusChanged();
}

bool AccountListModel::getIsGeneralLogged()
{
    return m_isGeneralLoged;
}

void AccountListModel::setIsGeneralLogged(bool status)
{
    m_isGeneralLoged = status;
    emit statusChanged();
}

void AccountListModel::reload()
{
    QList<AccountItem *> loggedinAccountList = AccountService::instance()->getLoggedInAccountList();
    QList<AccountModel *> modelList = QList<AccountModel *>();
    AccountItem* accountItem = NULL;

    for (int i = 0; i < loggedinAccountList.count(); i++) {
        accountItem = loggedinAccountList.at(i);
        if (accountItem != NULL) {
            AccountModel* newModel = new AccountModel(accountItem, this);
            modelList.append(newModel);
        }
    }

    notifyResetList(modelList);
}
