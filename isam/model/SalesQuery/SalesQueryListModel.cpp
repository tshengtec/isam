#include "SalesQueryListModel.h"
#include "SalesQueryService.h"

SalesQueryListModel::SalesQueryListModel()
{
    reload();
}

int SalesQueryListModel::getCommodityClass()
{

}

void SalesQueryListModel::setCommodityClass(int comClass)
{

}

void SalesQueryListModel::reload()
{
    QList<Commodity *> commodityList = SalesQueryService::instance()->getList();
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
