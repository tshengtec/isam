#ifndef ACCOUNTLISTMODEL_H
#define ACCOUNTLISTMODEL_H
#include "ObjectListModel.h"
#include "AccountModel.h"

class AccountListModel : public ObjectListModel<AccountModel>
{
    Q_OBJECT
public:
    AccountListModel();

    Q_INVOKABLE bool loginAccount(QString type, QString name, QString password);
    Q_INVOKABLE bool forgetPassword();
    Q_PROPERTY(bool isAdminLogged READ getIsAdminLogged WRITE setIsAdminLogged NOTIFY statusChanged)
    Q_PROPERTY(bool isGeneralLogged READ getIsGeneralLogged WRITE setIsGeneralLogged NOTIFY statusChanged)

    bool getIsAdminLogged();
    void setIsAdminLogged(bool status);

    bool getIsGeneralLogged();
    void setIsGeneralLogged(bool status);

signals:
    void statusChanged();

private slots:
    void reload();

private:
    bool m_isAdminLogged;
    bool m_isGeneralLoged;
};

#endif // ACCOUNTLISTMODEL_H
