#include "SalesCommodityListModel.h"
#include "SalesCommodityService.h"

SalesCommodityListModel::SalesCommodityListModel()
{
    reload();
    connect(SalesCommodityService::instance(), SIGNAL(listChanged()), this, SLOT(reload()));
}

void SalesCommodityListModel::reload()
{
    QList<Commodity *> commodityList = SalesCommodityService::instance()->getList();
    QList<SalesCommodityModel *> modelList = QList<SalesCommodityModel *>();
    Commodity* commodity = NULL;

    for (int i = 0; i < commodityList.count(); i++) {
        commodity = commodityList.at(i);
        if (commodity != NULL) {
            SalesCommodityModel* newModel = new SalesCommodityModel(commodity, this);
            modelList.append(newModel);
        }
    }

    notifyResetList(modelList);

}
