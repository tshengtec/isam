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
    QList<QVariantMap> commodityList;

    for (int i = 0; i < salesList.count(); i++) {
        SalesNote* salesNote = salesList.at(i);
        if (salesNote != NULL && salesNote->getId() == id) {
            commodityList = salesNote->getList();
            break;
        }
    }

    for (int i = 0; i < commodityList.count(); i++) {
        BaseCommodityModel* newModel = new BaseCommodityModel(this);
        newModel->fromMap(commodityList.at(i));
        modelList.append(newModel);
    }

    notifyResetList(modelList);
}
