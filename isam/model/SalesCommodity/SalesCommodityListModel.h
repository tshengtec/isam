#ifndef SALESCOMMODITYLISTMODEL_H
#define SALESCOMMODITYLISTMODEL_H
#include "ObjectListModel.h"
#include "BaseCommodityModel.h"

class SalesCommodityListModel : public ObjectListModel<BaseCommodityModel>
{
    Q_OBJECT
public:
    SalesCommodityListModel();

private slots:
    void reload();
};

#endif // SALESCOMMODITYLISTMODEL_H
