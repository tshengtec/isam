#ifndef ACCOUNTLISTMODEL_H
#define ACCOUNTLISTMODEL_H
#include "ObjectListModel.h"
#include "AccountModel.h"

class AccountListModel : public ObjectListModel<AccountModel>
{
    Q_OBJECT
public:
    AccountListModel();
};

#endif // ACCOUNTLISTMODEL_H
