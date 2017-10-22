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
    Q_INVOKABLE bool settleMent(QVariantMap payMap);
    Q_INVOKABLE void onPendingOperation();
    Q_INVOKABLE void onGettingOperation();

    Q_PROPERTY(QString errorStr READ getErrorStr WRITE setErrorStr NOTIFY statusChanged)
    Q_PROPERTY(bool isPendingStatus READ getIsPendingStatus NOTIFY statusChanged)
    Q_PROPERTY(QString payway READ getPayway WRITE setPayway NOTIFY statusChanged)
    Q_PROPERTY(QString authCode READ getAuthCode WRITE setAuthCode NOTIFY statusChanged)
    Q_PROPERTY(float paywayTotal READ getPaywayTotal WRITE setPaywayTotal NOTIFY statusChanged)


    QString getErrorStr();
    void setErrorStr(QString errorStr);

    QString getPayway();
    void setPayway(QString payway);

    QString getAuthCode();
    void setAuthCode(QString authCode);

    float getPaywayTotal();
    void setPaywayTotal(float paywayTotal);

    bool getIsPendingStatus();

signals:
    void statusChanged();

private slots:
    void setPayInfo();

private:
    QString m_errorStr;
    bool m_isPendingStatus;
    QString m_payway;
    QString m_authCode;
    float m_paywayTotal;
};

#endif // SALESCOMMODITYEDITMODEL_H
