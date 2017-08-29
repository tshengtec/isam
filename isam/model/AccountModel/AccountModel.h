#ifndef ACCOUNTMODEL_H
#define ACCOUNTMODEL_H
#include "BaseItemModel.h"

class AccountModel : public BaseItemModel
{
    Q_OBJECT
public:
    AccountModel(QObject* parent = NULL);
    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY statusChanged)
    Q_PROPERTY(QString password READ getPassword WRITE setPassWord NOTIFY statusChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

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
    QString m_id;
    QString m_name;
    QString m_password;
    QString m_type;
};

#endif // ACCOUNTMODEL_H
