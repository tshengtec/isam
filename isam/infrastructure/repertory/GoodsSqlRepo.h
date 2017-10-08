#ifndef GOODSSQLREPO_H
#define GOODSSQLREPO_H

#include "NetworkService.h"

#include <QObject>
#include <QJsonObject>
#include <QSqlQuery>

class GoodsSqlRepo : public NetworkService
{
    Q_OBJECT
public:
    static GoodsSqlRepo* instance();
    void init();

    bool insert(QJsonObject jsonObj);
    QList<QVariantMap> getList();

private slots:
    void getGoodsList(QNetworkReply* reply);

private:
    GoodsSqlRepo();

private:
    /*所属店铺编号*/
    QString getShopNo();
    QString getUrlStr();

private:
    static GoodsSqlRepo* _instance;
    QSqlQuery m_sqlQuery;
    QNetworkRequest m_req;

};

#endif // GOODSSQLREPO_H
