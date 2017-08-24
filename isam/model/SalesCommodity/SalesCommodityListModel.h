#ifndef SALESCOMMODITYLISTMODEL_H
#define SALESCOMMODITYLISTMODEL_H
#include "ObjectListModel.h"
#include "SalesCommodityModel.h"

class SalesCommodityListModel : public ObjectListModel<SalesCommodityModel>
{
    Q_OBJECT
public:
    SalesCommodityListModel();

private slots:
    void reload();
};

#endif // SALESCOMMODITYLISTMODEL_H
