#ifndef SALESQUERYLISTMODEL_H
#define SALESQUERYLISTMODEL_H
#include "ObjectListModel.h"
#include "BaseCommodityModel.h"
#include "EnumComplete.h"

class SalesQueryListModel : public ObjectListModel<BaseCommodityModel>
{
    Q_OBJECT
public:
    SalesQueryListModel();

public slots:
    Q_INVOKABLE void reload(QString id); //salseDocmentList id
};

#endif // SALESQUERYLISTMODEL_H
