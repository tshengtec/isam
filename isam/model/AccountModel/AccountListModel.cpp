#include "AccountListModel.h"
#include "AccountService.h"
#include <QDesktopServices>
#include <QUrl>

AccountListModel::AccountListModel()
{
    connect(AccountService::instance(), SIGNAL(loggedInAccountListChanged()), this, SLOT(reload()));
}

bool AccountListModel::loginAccount(QString type, QString name, QString password)
{
    return AccountService::instance()->loginAccount(type, name, password);
}

void AccountListModel::forgetPassword()
{
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));
}

bool AccountListModel::getIsAdminLogged()
{
    bool isAdminLogged = this->size() == 1;
    return isAdminLogged;
}

bool AccountListModel::getIsGeneralLogged()
{
    bool isAdminLogged = this->size() == 2;
    return isAdminLogged;
}

QString AccountListModel::getAdminAccount()
{
    for (int i = 0; i < this->size(); i++) {
        if (this->getItemList().at(i)->getType() == "admin") {
            return this->getItemList().at(i)->getName();
        }
    }

    return "";
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
    emit statusChanged();
}
