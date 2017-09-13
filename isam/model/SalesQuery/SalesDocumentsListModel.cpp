#include "SalesDocumentsListModel.h"
#include "SalesCommodityService.h"

SalesDocumentsListModel::SalesDocumentsListModel()
{
    m_sales = "0.00";
    m_salesNumber = 0;
}

QString SalesDocumentsListModel::getSales()
{
    return m_sales;
}

void SalesDocumentsListModel::setSales(QString sales)
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
        QString amountMoney = QString::number(salesItemModel->getRealIncome(), 'f', 2);
        salesDocModel->setAmountMoney(amountMoney);
        salesDocListModel.append(salesDocModel);
    }

    notifyResetList(salesDocListModel);

    QString sales = QString::number(SalesCommodityService::instance()->getSales(), 'f', 2);
    this->setSales(sales);
    int salesNumber = SalesCommodityService::instance()->getSalesList().count();
    this->setSalesNumber(salesNumber);
}
