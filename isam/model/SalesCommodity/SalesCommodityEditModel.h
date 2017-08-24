#ifndef SALESCOMMODITYEDITMODEL_H
#define SALESCOMMODITYEDITMODEL_H

#include "SalesCommodityModel.h"
#include "SalesCommodityService.h"

class SalesCommodityEditModel : public SalesCommodityModel
{
    Q_OBJECT
public:
    SalesCommodityEditModel();
    Q_INVOKABLE bool add(QString id);
    Q_INVOKABLE bool remove(QString id);
    Q_INVOKABLE bool update(Commodity *commodity);
};

#endif // SALESCOMMODITYEDITMODEL_H
