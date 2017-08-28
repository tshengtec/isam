#include "SalesQueryListModel.h"
#include "SalesQueryService.h"
#include "SalesCommodityService.h"

SalesQueryListModel::SalesQueryListModel()
{

}

void SalesQueryListModel::reload(QString id)
{
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();

    QList<SalesNote *> salesList = SalesCommodityService::instance()->getSalesList();
    QList<Commodity *> commodityList;
    Commodity* commodity = NULL;

    for (int i = 0; i < salesList.count(); i++) {
        SalesNote* salesNote = salesList.at(i);
        if (salesNote != NULL && salesNote->getId() == id) {
            commodityList = salesNote->getList();
            break;
        }
    }

    for (int i = 0; i < commodityList.count(); i++) {
        commodity = commodityList.at(i);
        if (commodity != NULL) {
            BaseCommodityModel* newModel = new BaseCommodityModel(commodity, this);
            modelList.append(newModel);
        }
    }

    notifyResetList(modelList);
}
