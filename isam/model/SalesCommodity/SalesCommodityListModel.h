#ifndef SALESCOMMODITYLISTMODEL_H
#define SALESCOMMODITYLISTMODEL_H
#include "ObjectListModel.h"
#include "BaseCommodityModel.h"

class SalesCommodityListModel : public ObjectListModel<BaseCommodityModel>
{
    Q_OBJECT
public:
    SalesCommodityListModel();
    Q_PROPERTY(QString amountMoney READ getAmountMoney NOTIFY statusChanged)
    Q_PROPERTY(int totalQuantity READ getTotalQuantity NOTIFY statusChanged)

    QString getAmountMoney();
    void setAmountMoney(QString money);

    int getTotalQuantity();
    void setTotalQuantity(int totalQuantity);

signals:
    void statusChanged();

private slots:
    void reload();

private:
    QString m_amountMoney;
    int m_totalQuantity;
};

#endif // SALESCOMMODITYLISTMODEL_H
