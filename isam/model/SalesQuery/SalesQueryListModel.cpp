#include "SalesQueryListModel.h"
#include "SalesQueryService.h"

SalesQueryListModel::SalesQueryListModel()
{
    m_searchText = "";
    m_commodityType = "all";
    reload();
    connect(this, SIGNAL(statusChanged()), this, SLOT(reload()));

}

QString SalesQueryListModel::getSearchText()
{
    return m_searchText;
}

void SalesQueryListModel::setSearchText(QString text)
{
    m_searchText = text;
    emit statusChanged();
}

QString SalesQueryListModel::getCommodityType()
{
    return m_commodityType;
}

void SalesQueryListModel::setCommodityType(QString typeStr)
{
    m_commodityType = typeStr;
    emit statusChanged();
}

void SalesQueryListModel::reload()
{
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();
    if (this->getSearchText() == "") {
        notifyResetList(modelList);
        return;
    }

    QueryCommodityCondition condition;
    condition.setCommodityType(this->getCommodityType());
    condition.setFuzzyStr(this->getSearchText());

    QList<Commodity *> commodityList = SalesQueryService::instance()->getList(condition);
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
