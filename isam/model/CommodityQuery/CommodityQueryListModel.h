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
    Q_PROPERTY(bool isNotStrSearchAll READ getIsNotStrSearchAll WRITE setIsNotStrSearchAll NOTIFY statusChanged)
    Q_PROPERTY(QStringList commodityTypeList READ getCommodityTypeList NOTIFY statusChanged)
    Q_PROPERTY(int total READ getTotal NOTIFY totalChanged)

    QString getCommodityType();
    void setCommodityType(QString typeStr);

    QString getSearchText();
    void setSearchText(QString text);

    bool getIsNotStrSearchAll();
    void setIsNotStrSearchAll(bool status);

    QStringList getCommodityTypeList();
    void setCommodityTypeList();

    int getTotal();

signals:
    void statusChanged();
    void totalChanged();

public slots:
    Q_INVOKABLE void reload();

private:
    QString m_commodityType;
    QString m_searchText;
    bool m_isNotStrSearchAll;
    QStringList m_commodityTypeList;
};

#endif // COMMODITYQUERYLISTMODEL_H
