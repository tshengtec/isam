#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Themes.h"
#include "CommodityRepertory.h"

#include "SalesCommodityEditModel.h"
#include "SalesCommodityListModel.h"

#define BACKGROUNDCOLOR "#1f29f9"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<SalesCommodityEditModel>("MyModels", 1, 0, "SalesCommodityEditModel");
    qmlRegisterType<SalesCommodityListModel>("MyModels", 1, 0, "SalesCommodityListModel");

    QQmlApplicationEngine engine;

    Themes* themes = new Themes();
    themes->setBackgroundColor(BACKGROUNDCOLOR);
    engine.rootContext()->setContextProperty("themesModel", themes);

    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));

    return app.exec();
}
