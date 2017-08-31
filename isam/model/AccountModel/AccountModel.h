#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H
#include "BaseItemModel.h"
#include "AccountService.h"
/*
 * note: The reserved interface is temporarily useless!
 */
class AccountModel : public BaseItemModel
{
    Q_OBJECT
public:
    AccountModel(QObject* parent = NULL);

    Q_INVOKABLE bool verifyAccount(QString type, QString name, QString password);
    Q_PROPERTY(bool isAdminLogged READ getIsAdminLogged WRITE setIsAdminLogged NOTIFY statusChanged)
    Q_PROPERTY(bool isGeneralLogged READ getIsGeneralLogged WRITE setIsGeneralLogged NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY statusChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY statusChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY statusChanged)

    bool getIsAdminLogged();
    void setIsAdminLogged(bool status);

    bool getIsGeneralLogged();
    void setIsGeneralLogged(bool status);

    QString getName();
    void setName(QString name);

    QString getPassword();
    void setPassword(QString password);

    QString getType();
    void setType(QString type);

    void operator=(const AccountModel& model);

signals:
    void statusChanged();

private:
    bool m_isAdminLogged;
    bool m_isGeneralLoged;
    QString m_name;
    QString m_password;
    QString m_type;
};

#endif // ACCOUNTMODEL_H
