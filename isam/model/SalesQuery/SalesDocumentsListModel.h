#ifndef SALESDOCUMENTSLISTMODEL_H
#define SALESDOCUMENTSLISTMODEL_H
#include "ObjectListModel.h"
#include "SalesDocumentsModel.h"

class SalesDocumentsListModel : public ObjectListModel<SalesDocumentsModel>
{
    Q_OBJECT
public:
    SalesDocumentsListModel();
    Q_INVOKABLE void reload();
    Q_PROPERTY(float sales READ getSales NOTIFY statusChanged)
    Q_PROPERTY(int salesNumber READ getSalesNumber NOTIFY statusChanged)

    float getSales();
    void setSales(float sales);

    int getSalesNumber();
    void setSalesNumber(int num);

signals:
    void statusChanged();

private:
    float m_sales;
    int m_salesNumber;
};

#endif // SALESDOCUMENTSLISTMODEL_H
