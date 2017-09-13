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
    Q_PROPERTY(QString sales READ getSales NOTIFY statusChanged)
    Q_PROPERTY(int salesNumber READ getSalesNumber NOTIFY statusChanged)

    QString getSales();
    void setSales(QString sales);

    int getSalesNumber();
    void setSalesNumber(int num);

signals:
    void statusChanged();

private:
    QString m_sales;
    int m_salesNumber;
};

#endif // SALESDOCUMENTSLISTMODEL_H
