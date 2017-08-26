#ifndef SALESQUERYLISTMODEL_H
#define SALESQUERYLISTMODEL_H
#include "ObjectListModel.h"
#include "BaseCommodityModel.h"
#include "EnumComplete.h"

class SalesQueryListModel : public ObjectListModel<BaseCommodityModel>
{
    Q_OBJECT
public:
    Q_ENUMS(aa)
    SalesQueryListModel();
    Q_PROPERTY(int commodityClass READ getCommodityClass WRITE setCommodityClass NOTIFY statusChanged)

    int getCommodityClass();
    void setCommodityClass(int comClass);

signals:
    void statusChanged();

private slots:
    void reload();

private:
    EC::CommodityClassification aa;
};

#endif // SALESQUERYLISTMODEL_H
