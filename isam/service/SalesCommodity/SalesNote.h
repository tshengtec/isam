#ifndef SALESNOTE_H
#define SALESNOTE_H
#include "Commodity.h"
#include <QDateTime>
#include <QVariantMap>

const QString paymentType[] = {
              "moneyPay", "weChatPay", "aliPay"
};

class SalesNote
{
public:
    SalesNote();
    SalesNote(SalesNote* salesNote);
    virtual ~SalesNote();

    QList<QVariantMap> getList();
    void setList(QList<QVariantMap> list);

    QVariantMap get(QString id);
    bool add(QString id); /*Commodity id*/
    bool remove(QString id); /*Commodity id*/
    bool update(QVariantMap commodity); /*TODO*/
    bool removeAll(); /*removeAll m_commodityList*/
    QList<QVariantMap> copyMyselfList();

    QString getId();
    void setId(QString id);

    QString getOwner();
    void setOwner(QString owner);

    QDateTime getDateTime();
    void setDateTime(QDateTime dateTime);

    /*Payment methods and amount*/
    QVariantMap getPaymentMethodsAndAmout();
    void setPaymentMethodsAndAmout(QVariantMap map);

    /*Realized income.*/
    float getRealIncome();

    /*Total goods quantity.*/
    int getTotalQuantity();

private:
    QList<QVariantMap> copyList(QList<QVariantMap > list);
    void removeList(QList<QVariantMap >& removeList); // remove List
    bool isRepeatedAdd(QVariantMap map);

private:
    QList<QVariantMap > m_commodityList;
    QString m_id;    /*ID*/
    QString m_owner; /*Sales staff.*/
    QDateTime m_dateTime; /*Time for selling.*/
    /*
     * Payment method and amount of payment.
     * Such as: {"cash": 20}, {"wxpay": 20}, {"alipay": 0}
     */
    QVariantMap m_paymentMethodsAndAmout;
};

#endif // SALESNOTE_H
