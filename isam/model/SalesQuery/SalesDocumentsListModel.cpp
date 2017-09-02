#include "SalesDocumentsListModel.h"
#include "SalesCommodityService.h"

SalesDocumentsListModel::SalesDocumentsListModel()
{
    m_sales = 0;
    m_salesNumber = 0;
}

float SalesDocumentsListModel::getSales()
{
    return m_sales;
}

void SalesDocumentsListModel::setSales(float sales)
{
    m_sales = sales;
    emit statusChanged();
}

int SalesDocumentsListModel::getSalesNumber()
{
    return m_salesNumber;
}

void SalesDocumentsListModel::setSalesNumber(int num)
{
    m_salesNumber = num;
    emit statusChanged();
}

void SalesDocumentsListModel::reload()
{
    QList<SalesNote *> salesList = SalesCommodityService::instance()->getSalesList();
    QList<SalesDocumentsModel *> salesDocListModel = QList<SalesDocumentsModel *>();

    SalesNote* salesItemModel = NULL;
    for (int i = 0; i < salesList.count(); i++) {
        salesItemModel = salesList.at(i);
        if (salesItemModel == NULL)
            return;

        SalesDocumentsModel* salesDocModel = new SalesDocumentsModel(this);
        salesDocModel->setTime(salesItemModel->getDateTime().time());
        salesDocModel->setId(salesItemModel->getId());
        salesDocModel->setAmountMoney(0);
        salesDocListModel.append(salesDocModel);
    }

    notifyResetList(salesDocListModel);

    float sales = SalesCommodityService::instance()->getSales();
    this->setSales(sales);
    int salesNumber = SalesCommodityService::instance()->getSalesList().count();
    this->setSalesNumber(salesNumber);
}
