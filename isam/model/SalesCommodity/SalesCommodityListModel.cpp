#include "SalesCommodityListModel.h"
#include "SalesCommodityService.h"

SalesCommodityListModel::SalesCommodityListModel()
{
    m_amountMoney = "0.00";
    reload();
    connect(SalesCommodityService::instance(), SIGNAL(listChanged()), this, SLOT(reload()));
}

QString SalesCommodityListModel::getAmountMoney()
{
    return m_amountMoney;
}

void SalesCommodityListModel::setAmountMoney(QString money)
{
    m_amountMoney = money;
    emit statusChanged();
}

void SalesCommodityListModel::reload()
{
    SalesNote salesNote = SalesCommodityService::instance()->getSalesNote();
    QList<Commodity *> commodityList = salesNote.getList();
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

    this->setAmountMoney(QString::number(salesNote.getRealIncome(), 'f', 2));
}
