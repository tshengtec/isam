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

int SalesCommodityListModel::getTotalQuantity()
{
    return m_totalQuantity;
}

void SalesCommodityListModel::setTotalQuantity(int totalQuantity)
{
    m_totalQuantity = totalQuantity;
    emit statusChanged();
}

void SalesCommodityListModel::reload()
{
    SalesNote salesNote = SalesCommodityService::instance()->getSalesNote();
    QList<QVariantMap> commodityList = salesNote.getList();
    QList<BaseCommodityModel *> modelList = QList<BaseCommodityModel *>();

    for (int i = 0; i < commodityList.count(); i++) {
        BaseCommodityModel* newModel = new BaseCommodityModel(this);
        newModel->fromMap(commodityList.at(i));
        modelList.append(newModel);
    }

    notifyResetList(modelList);

    this->setAmountMoney(QString::number(salesNote.getRealIncome(), 'f', 2));
    this->setTotalQuantity(salesNote.getTotalQuantity());
}
