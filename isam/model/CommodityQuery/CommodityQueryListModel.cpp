#include "CommodityQueryListModel.h"
#include "CommodityQueryService.h"

CommodityQueryListModel::CommodityQueryListModel()
{
    m_searchText = "";
    m_commodityType = "all";
    reload();
    connect(this, SIGNAL(statusChanged()), this, SLOT(reload()));

}

QString CommodityQueryListModel::getSearchText()
{
    return m_searchText;
}

void CommodityQueryListModel::setSearchText(QString text)
{
    m_searchText = text;
    emit statusChanged();
}

QString CommodityQueryListModel::getCommodityType()
{
    return m_commodityType;
}

void CommodityQueryListModel::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
    emit statusChanged();
}

void CommodityQueryListModel::reload()
{
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();
    if (this->getSearchText() == "") {
        notifyResetList(modelList);
        return;
    }

    CommodityQueryCondition condition;
    condition.setCommodityType(this->getCommodityType());
    condition.setFuzzyStr(this->getSearchText());

    QList<Commodity *> commodityList = CommodityQueryService::instance()->getList(condition);
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
