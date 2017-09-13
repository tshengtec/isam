#ifndef SALESDOCUMENTSMODEL_H
#define SALESDOCUMENTSMODEL_H
#include "BaseItemModel.h"
#include <QTime>

class SalesDocumentsModel : public BaseItemModel
{
    Q_OBJECT
public:
    SalesDocumentsModel(QObject* parent = NULL);
    Q_PROPERTY(QString id READ getId NOTIFY statusChanged)
    Q_PROPERTY(QString amountMoney READ getAmountMoney NOTIFY statusChanged)
    Q_PROPERTY(QTime time READ getTime NOTIFY statusChanged)

    QString getId();
    void setId(QString id);

    QTime getTime();
    void setTime(QTime time);

    QString getAmountMoney();
    void setAmountMoney(QString money);

    void operator=(const SalesDocumentsModel& model);

signals:
    void statusChanged();

private:
    QString m_id; //SalesDocumentsModel id
    QTime m_time;
    QString m_amountMoney;
};

#endif // SALESDOCUMENTSMODEL_H
