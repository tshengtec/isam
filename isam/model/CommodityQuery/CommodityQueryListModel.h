#ifndef COMMODITYQUERYLISTMODEL_H
#define COMMODITYQUERYLISTMODEL_H
#include "ObjectListModel.h"
#include "BaseCommodityModel.h"
#include "EnumComplete.h"

class CommodityQueryListModel : public ObjectListModel<BaseCommodityModel>
{
    Q_OBJECT
public:
    CommodityQueryListModel();
    Q_PROPERTY(QString commodityType READ getCommodityType WRITE setCommodityType NOTIFY statusChanged)
    Q_PROPERTY(QString searchText READ getSearchText WRITE setSearchText NOTIFY statusChanged)

    QString getCommodityType();
    void setCommodityType(QString typeStr);

    QString getSearchText();
    void setSearchText(QString text);

signals:
    void statusChanged();

private slots:
    Q_INVOKABLE void reload();

private:
    QString m_commodityType;
    QString m_searchText;
};

#endif // COMMODITYQUERYLISTMODEL_H
