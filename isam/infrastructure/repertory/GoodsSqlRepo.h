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
    void update();

    bool insert(QJsonObject jsonObj);
    QList<QVariantMap> getList();
    QList<QVariantMap> getList(QString target, int page =1, int pageNum = 10);

private slots:
    void getGoodsList(QNetworkReply* reply);

private:
    GoodsSqlRepo();

private:
    /*所属店铺编号*/
    QString getShopNo();
    QString getUrlStr(QString str);
    void createGoodsFields();
    QJsonObject filterJsonObj(QJsonObject target);

private:
    static GoodsSqlRepo* _instance;
    QSqlQuery m_sqlQuery;
    QSqlDatabase m_db;
    QNetworkRequest m_req;
};

#endif // GOODSSQLREPO_H
