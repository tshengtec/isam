#include "SalesDocumentsListModel.h"
#include "SalesCommodityService.h"

SalesDocumentsListModel::SalesDocumentsListModel()
{

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
}
