#include "AccountService.h"
#include "JsonListConvertor.h"
#include "CommodityCategoryNetworkService.h"

#include <QCryptographicHash>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>

AccountService * AccountService::_instance = NULL;


AccountService::AccountService()
{
    m_delayInit.setSingleShot(true);
    m_delayInit.setInterval(1000);
    m_delayInit.start();
    connect(this, SIGNAL(listChanged()), this, SLOT(save()));
    connect(&m_networkService, SIGNAL(returnLoginStatus(bool)), this, SLOT(getLoginStatus(bool)) );
    connect(&m_delayInit, SIGNAL(timeout()), this, SLOT(reload()));
}

AccountItem* AccountService::getAdminAccount() const
{
    for (int i = 0; i < this->m_accountList.count(); i++) {
        if (accountTypeList[0] == this->m_accountList.at(i)->getType()) {
            return this->m_accountList.at(i);
        }
    }
    return NULL;
}

void AccountService::getLoginStatus(bool status)
{
    bool isSuccess = status;
    if (isSuccess) {
        for (int index = 0; index < sizeof(accountTypeList)/sizeof(accountTypeList[0]); index++) {
            QString accountType = m_networkService.getJsonObj().value("type").toString();
            if (accountTypeList[index] == accountType) {
                AccountItem* loggedInaccountItem = new AccountItem(m_networkService.getJsonObj());
                m_loggedInAccountList.append(loggedInaccountItem);
            }

            if (m_accountList.count() == 0 && accountTypeList[0] == accountType) { //admin user
                m_accountList.append(new AccountItem(m_networkService.getJsonObj()));
                emit listChanged();
            }

            if (accountTypeList[1] == accountType) {
                modifyConfigFile();
            }
        }
        m_error = "";
    }
    else {
        m_error = m_networkService.getJsonObj().value("error").toString();
    }
    emit loggedInAccountListChanged();
}

void AccountService::save()
{
    JsonListConvertor<AccountItem> convertor;
    QJsonValue jsonValue = convertor.toJson(m_accountList);

    QFile configFile("config.json");
    configFile.open(QIODevice::ReadWrite);

    QJsonParseError error;
    QJsonDocument saveDoc = QJsonDocument::fromJson(configFile.readAll(), &error);

    QJsonObject newJsonObj = saveDoc.object();
    newJsonObj.insert("accountInfoArray", jsonValue.toArray());

    configFile.resize(0);
    configFile.write(QJsonDocument(newJsonObj).toJson());
    configFile.close();
}

bool AccountService::loginAccount(QString type, QString name, QString password)
{
    if (!m_networkService.isNetworkConnection()) {
        m_error = "网络错误";
        emit loggedInAccountListChanged();
        return false;
    }

    if (type == accountTypeList[1]) {
        AccountItem* adminAccount = this->getAdminAccount();
        if (adminAccount != NULL) {
            QString adminName = this->getAdminAccount()->getName();
            m_networkService.getAccountInfo(adminName + ":" + name, password, type);
            /*Login success!*/
        }
    }
    else {
        m_networkService.getAccountInfo(name, password, type);
    }
    return true;
}

QList<AccountItem *> AccountService::getLoggedInAccountList()
{
    return m_loggedInAccountList;
}

QString AccountService::getError()
{
    return m_error;
}

void AccountService::finishedSlot(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();  // bytes
    QString jsonString = QString::fromUtf8(bytes);
    qDebug()<<jsonString<<"jsonString>>>>>";
}

bool AccountService::logoutAccount(QString type, QString name)
{
    for (int i = 0; i < this->m_loggedInAccountList.count(); i++) {
        AccountItem* item = m_loggedInAccountList.at(i);
        if (item != NULL && item->getType() == type && item->getName() == name) {
            m_loggedInAccountList.removeAt(i);
            delete item;
            emit loggedInAccountListChanged();
            if (accountTypeList[0] == type) //is admin account
                this->remove(name);
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

bool AccountService::remove(QString account)
{
    for (int index = 0; index < m_accountList.count(); index++) {
        AccountItem* item = this->m_accountList.at(index);
        if (account != item->getName())
            continue;
        m_accountList.removeAt(index);
        delete item;
        emit listChanged();
        return true;
    }

    return false;
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
    m_accountList = verifyAccountListIsValid(convertor.toList(jsonList));

    for ( int i = 0 ; i < m_accountList.count(); i++) {
        AccountItem* item = m_accountList.at(i);

        if (accountTypeList[0] == item->getType()) {
            AccountItem* loggedInaccountItem = new AccountItem(m_accountList.at(i));
            m_loggedInAccountList.append(loggedInaccountItem);
            emit loggedInAccountListChanged();
            break;
        }
    }
    emit listChanged();
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

QList<AccountItem *> AccountService::verifyAccountListIsValid(QList<AccountItem *> list)
{
    QList<AccountItem *> accountList = list;
    for ( int i = 0 ; i < accountList.count(); i++) {
        AccountItem* item = accountList.at(i);
        if (!this->verifyAccountIsValid(item->getType(), item->getName(), item->getPasswordMD5())) {
            accountList.removeAt(i);
            delete item;
            i = 0;
        }
    }
    return accountList;
}

void AccountService::modifyConfigFile()
{
//    QNetworkRequest* req = new QNetworkRequest();
//    req->setRawHeader(QByteArray("Token"),
//                      QByteArray(m_networkService.getJsonObj().value("accessToken").toString().toStdString().c_str()));
//    QNetworkAccessManager* man = new QNetworkAccessManager();
//    req->setUrl(QUrl("http://api.cashier.slktea.com/isam-web-cashier/v1/shop_goods?shopNo=111111&pageNum=1&numPerPage=2"));
//    man->get(*req);

//    connect(man, SIGNAL(finished(QNetworkReply*)), this, SLOT(finishedSlot(QNetworkReply*)));

    CommodityCategoryNetworkService* commodityCategoryNetworkService = new CommodityCategoryNetworkService();

    QFile configFile("config.json");
    configFile.open(QIODevice::ReadWrite);

    QJsonParseError error;
    QJsonDocument saveDoc = QJsonDocument::fromJson(configFile.readAll(), &error);

    if  ( error.error == QJsonParseError::NoError && saveDoc.isObject()) {
        QJsonObject newJsonObj = saveDoc.object();
        newJsonObj.insert("loginInfo", m_networkService.getJsonObj());

        configFile.resize(0);
        configFile.write(QJsonDocument(newJsonObj).toJson());
    }
    else {
        qDebug()<<"AccountService"<<error.errorString();
    }
    configFile.close();
}

AccountService *AccountService::instance()
{
    if (_instance == NULL) {
        _instance = new AccountService();
    }
    return _instance;
}
