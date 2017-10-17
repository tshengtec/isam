#ifndef SALESCOMMODITYEDITMODEL_H
#define SALESCOMMODITYEDITMODEL_H

#include "BaseCommodityModel.h"
#include "SalesCommodityService.h"

class SalesCommodityEditModel : public BaseCommodityModel
{
    Q_OBJECT
public:
    SalesCommodityEditModel();

    Q_INVOKABLE bool add(QString id);
    Q_INVOKABLE bool remove(QString id);
    Q_INVOKABLE bool removeAll();
    Q_INVOKABLE bool update(QVariantMap commodity);
    Q_INVOKABLE bool settleMent();
    Q_INVOKABLE void onPendingOperation();
    Q_INVOKABLE void onGettingOperation();

    Q_PROPERTY(QString errorStr READ getErrorStr WRITE setErrorStr NOTIFY statusChanged)
    Q_PROPERTY(bool isPendingStatus READ getIsPendingStatus NOTIFY statusChanged)

    QString getErrorStr();
    void setErrorStr(QString errorStr);

    bool getIsPendingStatus();

signals:
    void statusChanged();

private:
    QString m_errorStr;
    bool m_isPendingStatus;
};

#endif // SALESCOMMODITYEDITMODEL_H
