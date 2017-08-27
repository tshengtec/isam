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

#endif // SALESQUERYLISTMODEL_H
