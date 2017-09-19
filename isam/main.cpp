#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "Themes.h"
#include "CommodityRepertory.h"
#include "QmlWin.h"
#include "MyGuiApplication.h"

#include "SalesCommodityEditModel.h"
#include "SalesCommodityListModel.h"
#include "CommodityQueryListModel.h"
#include "SalesQueryListModel.h"
#include "SalesDocumentsListModel.h"
#include "AccountListModel.h"
#include "EnumComplete.h"
#include "NetworkService.h"

#define BACKGROUNDCOLOR "#1f29f9"

int main(int argc, char *argv[])
{
    NetworkService* netService = new NetworkService();
    netService->getAccountInfo("jinhai", "j", accountTypeList[0]);
    MyGuiApplication app(argc, argv);

    qmlRegisterType<EnumComplete>("MyModels", 1, 0, "EnumComplete");
    qmlRegisterType<SalesCommodityEditModel>("MyModels", 1, 0, "SalesCommodityEditModel");
    qmlRegisterType<SalesCommodityListModel>("MyModels", 1, 0, "SalesCommodityListModel");
    qmlRegisterType<CommodityQueryListModel>("MyModels", 1, 0, "CommodityQueryListModel");
    qmlRegisterType<SalesQueryListModel>("MyModels", 1, 0, "SalesQueryListModel");
    qmlRegisterType<SalesDocumentsListModel>("MyModels", 1, 0, "SalesDocumentsListModel");
    qmlRegisterType<AccountListModel>("MyModels", 1, 0, "AccountListModel");

    QmlWin* win = new QmlWin();
    return app.exec();
}

//http://api.erp.slktea.com/isam-web-merchant/auth?account=jinhai&password=e10adc3949ba59abbe56e057f20f883e
