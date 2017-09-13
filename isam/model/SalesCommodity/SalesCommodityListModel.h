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

    QString getAmountMoney();
    void setAmountMoney(QString money);

signals:
    void statusChanged();

private slots:
    void reload();

private:
    QString m_amountMoney;
};

#endif // SALESCOMMODITYLISTMODEL_H
