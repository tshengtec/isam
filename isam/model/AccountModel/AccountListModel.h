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
    Q_INVOKABLE void forgetPassword();
    Q_PROPERTY(bool isAdminLogged READ getIsAdminLogged  NOTIFY statusChanged)
    Q_PROPERTY(bool isGeneralLogged READ getIsGeneralLogged NOTIFY statusChanged)

    bool getIsAdminLogged();
    bool getIsGeneralLogged();

signals:
    void statusChanged();

private slots:
    void reload();
};

#endif // ACCOUNTLISTMODEL_H
