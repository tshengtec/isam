#include "CommodityQueryListModel.h"
#include "CommodityQueryService.h"

CommodityQueryListModel::CommodityQueryListModel()
{
    m_searchText = "";
    m_commodityType = "all";
    m_isNotStrSearchAll = false;
    this->setCommodityTypeList();

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

bool CommodityQueryListModel::getIsNotStrSearchAll()
{
    return m_isNotStrSearchAll;
}

void CommodityQueryListModel::setIsNotStrSearchAll(bool status)
{
    m_isNotStrSearchAll = status;
    emit statusChanged();
}

QStringList CommodityQueryListModel::getCommodityTypeList()
{
    return m_commodityTypeList;
}

void CommodityQueryListModel::setCommodityTypeList()
{
    int count = sizeof(commodityTypeListTr)/sizeof(QString);
    for (int i = 0; i < count; i++) {
        m_commodityTypeList.append(commodityTypeListTr[i]);
    }
}

QString CommodityQueryListModel::getCommodityType()
{
    return m_commodityType;
}

void CommodityQueryListModel::setCommodityType(QString typeStr)
{
    int count = sizeof(commodityTypeListTr)/sizeof(QString);
    for (int i = 0; i < count; i++) {
        if (commodityTypeListTr[i] == typeStr) {
            typeStr = commodityTypeList[i];
            break;
        }
    }
    m_commodityType = typeStr;
    emit statusChanged();
}

int CommodityQueryListModel::getTotal()
{
    int total = this->size();
    return total;
}

void CommodityQueryListModel::reload()
{
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();

    CommodityQueryCondition condition;
    condition.setCommodityType(this->getCommodityType());
    condition.setFuzzyStr(this->getSearchText());
    condition.setIsNotStrSearchAll(this->getIsNotStrSearchAll());

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
    emit totalChanged();
}
