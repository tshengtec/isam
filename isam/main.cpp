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

#define BACKGROUNDCOLOR "#1f29f9"

int main(int argc, char *argv[])
{
    QString password("123456");
    QByteArray bb;
    bb = QCryptographicHash::hash( password.toLatin1(), QCryptographicHash::Md5 );
    qDebug()<<bb.toHex()<<">>>>>>";

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
