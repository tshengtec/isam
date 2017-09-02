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
    AccountModel(AccountItem* accountItem, QObject* parent = NULL);

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY statusChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassword NOTIFY statusChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY statusChanged)

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
    QString m_name;
    QString m_password;
    QString m_type;
};

#endif // ACCOUNTMODEL_H
