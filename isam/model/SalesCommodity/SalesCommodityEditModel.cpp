#include "SalesCommodityEditModel.h"

SalesCommodityEditModel::SalesCommodityEditModel()
{

}

bool SalesCommodityEditModel::add(QString id)
{
    return SalesCommodityService::instance()->add(id);
}

bool SalesCommodityEditModel::remove(QString id)
{
    return SalesCommodityService::instance()->remove(id);
}

bool SalesCommodityEditModel::update(Commodity *commodity)
{
    return SalesCommodityService::instance()->update(commodity);
}
