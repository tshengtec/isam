#ifndef SALESDOCUMENTSLISTMODEL_H
#define SALESDOCUMENTSLISTMODEL_H
#include "ObjectListModel.h"
#include "SalesDocumentsModel.h"

class SalesDocumentsListModel : public ObjectListModel<SalesDocumentsModel>
{
    Q_OBJECT
public:
    SalesDocumentsListModel();

    Q_INVOKABLE void reload();
};

#endif // SALESDOCUMENTSLISTMODEL_H
