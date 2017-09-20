#include "AccountService.h"
#include "JsonListConvertor.h"
#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>

AccountService * AccountService::_instance = NULL;


AccountService::AccountService()
{
    connect(this, SIGNAL(listChanged()), this, SLOT(save()));
    connect(&m_networkService, SIGNAL(returnLoginStatus(bool)), this, SLOT(getLoginStatus(bool)) );
}

void AccountService::getLoginStatus(bool status)
{
    bool isSuccess = status;
    if (isSuccess) {
        for (int index = 0; index < sizeof(accountTypeList)/sizeof(accountTypeList[0]); index++) {
            QString accountType = m_networkService.getJsonObj().value("accountType").toString();
            if (accountTypeList[index] == accountType) {
                AccountItem* loggedInaccountItem = new AccountItem(m_networkService.getJsonObj());
                m_loggedInAccountList.append(loggedInaccountItem);

                if (m_accountList.count() == 0) {
                    m_accountList.append(new AccountItem(m_networkService.getJsonObj()));
                    emit listChanged();
                }

                emit loggedInAccountListChanged();
            }
        }
    }
}

void AccountService::save()
{
    JsonListConvertor<AccountItem> convertor;
    QJsonValue jsonValue = convertor.toJson(m_accountList);

    QFile configFile(QStringLiteral("config.json"));
    configFile.open(QIODevice::ReadWrite);

//    qDebug()<<configFile.readAll();
    QJsonParseError error;
    QJsonDocument saveDoc = QJsonDocument::fromJson(configFile.readAll(), &error);

    qDebug()<<saveDoc.object()<<error.errorString();
    QJsonObject newJsonObj = saveDoc.object();
    newJsonObj.insert("accountInfoArray", jsonValue.toArray());

    configFile.resize(0);
    configFile.write(QJsonDocument(newJsonObj).toJson());
    configFile.close();
}

bool AccountService::loginAccount(QString type, QString name, QString password)
{
    m_networkService.getAccountInfo(name, password, type);
//    if (m_accountList.count() > 0) {
//        for (int i = 0; i < m_accountList.count(); i++) {
//            AccountItem* accountItem = m_accountList.at(i);
//            if (accountItem->getType() == type &&
//                accountItem->getName() == name &&
//                accountItem->getPassword() == password) {
//                AccountItem* loggedInaccountItem = new AccountItem(accountItem);
//                m_loggedInAccountList.append(loggedInaccountItem);
//                emit loggedInAccountListChanged();
//                return true;
//            }
//        }
//    }
//    else {

//    }
//    return false;
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
    QFile configFile("config.json");
    configFile.open(QIODevice::ReadOnly);
    QByteArray saveData = configFile.readAll();

    QJsonDocument saveDoc(QJsonDocument::fromJson(saveData));

    QJsonArray jsonList = saveDoc.object().value("accountInfoArray").toArray();
    JsonListConvertor<AccountItem> convertor;
    m_accountList = convertor.toList(jsonList);
//    this->add(accountTypeList[0], "123456789@qq.com", "123456");
//    this->add(accountTypeList[1], "1001", "123456");
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
