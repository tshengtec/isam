#include "SalesCommodityListModel.h"
#include "SalesCommodityService.h"

SalesCommodityListModel::SalesCommodityListModel()
{
    reload();
    connect(SalesCommodityService::instance(), SIGNAL(listChanged()), this, SLOT(reload()));
}

void SalesCommodityListModel::reload()
{
    QList<Commodity *> commodityList = SalesCommodityService::instance()->getSalesNote()->getList();
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();
    Commodity* commodity = NULL;

    for (int i = 0; i < commodityList.count(); i++) {
        commodity = commodityList.at(i);
        if (commodity != NULL) {
            BaseCommodityModel* newModel = new BaseCommodityModel(commodity, this);
            modelList.append(newModel);
        }
    }

    notifyResetList(modelList);
}
