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
    virtual ~SalesNote();

    QList<Commodity *> getList();
    void setList(QList<Commodity *> list);

    QString getId();
    void setId(QString id);

    QString getOwner();
    void setOwner(QString owner);

    QDateTime getDateTime();
    void setDateTime(QDateTime dateTime);

    QVariantMap getPayMap();
    void setPayMap(QVariantMap map);

private:
    void removeList(QList<Commodity* >& removeList); // remove List

private:
    QList<Commodity* > m_salesBaseNote;
    QString m_id;    /*ID*/
    QString m_owner; /*Sales staff.*/
    QDateTime m_dateTime; /*Time for selling.*/
    /*
     * Payment method and amount of payment.
     * Such as: {"moneyPay": 10.0}, {"weChatPay": 20.0}, {"aliPay": 30.00}
     */
    QVariantMap m_payMap;
};

#endif // SALESNOTE_H
