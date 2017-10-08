#ifndef COMMODITYCATEGORYNETWORKSERVICE_H
#define COMMODITYCATEGORYNETWORKSERVICE_H

#include "NetworkService.h"

class CommodityCategoryNetworkService : public NetworkService
{
    Q_OBJECT
public:
    CommodityCategoryNetworkService();

private slots:
    void getCommodityCategoryList(QNetworkReply* reply);

private:
    /*所属店铺编号*/
    QString getShopNo();
    QString getUrlStr();
};

#endif // COMMODITYCATEGORYNETWORKSERVICE_H
