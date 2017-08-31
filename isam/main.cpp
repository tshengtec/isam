#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Themes.h"
#include "CommodityRepertory.h"

#include "SalesCommodityEditModel.h"
#include "SalesCommodityListModel.h"
#include "CommodityQueryListModel.h"
#include "SalesQueryListModel.h"
#include "SalesDocumentsListModel.h"
#include "AccountModel.h"

#define BACKGROUNDCOLOR "#1f29f9"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SalesCommodityEditModel>("MyModels", 1, 0, "SalesCommodityEditModel");
    qmlRegisterType<SalesCommodityListModel>("MyModels", 1, 0, "SalesCommodityListModel");
    qmlRegisterType<CommodityQueryListModel>("MyModels", 1, 0, "CommodityQueryListModel");
    qmlRegisterType<SalesQueryListModel>("MyModels", 1, 0, "SalesQueryListModel");
    qmlRegisterType<SalesDocumentsListModel>("MyModels", 1, 0, "SalesDocumentsListModel");
    qmlRegisterType<AccountModel>("MyModels", 1, 0, "AccountModel");
    QQmlApplicationEngine engine;

    Themes* themes = new Themes();
    themes->setBackgroundColor(BACKGROUNDCOLOR);
    engine.rootContext()->setContextProperty("themesModel", themes);

    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));

    return app.exec();
}
