#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#if QT_VERSION >= QT_VERSION_CHECK(4, 0, 0)
#include <QtMsgHandler>
#endif
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

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
void customMessageHandler(QtMsgType type, const QMessageLogContext &, const QString & str)
{
    QString txt=str;
#else
void customMessageHandler(QtMsgType type, const char *msg)
{
    QString txt(msg);
#endif
    QFile outFile("debug.log");
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    MyGuiApplication app(argc, argv);

    qmlRegisterType<EnumComplete>("MyModels", 1, 0, "EnumComplete");
    qmlRegisterType<SalesCommodityEditModel>("MyModels", 1, 0, "SalesCommodityEditModel");
    qmlRegisterType<SalesCommodityListModel>("MyModels", 1, 0, "SalesCommodityListModel");
    qmlRegisterType<CommodityQueryListModel>("MyModels", 1, 0, "CommodityQueryListModel");
    qmlRegisterType<SalesQueryListModel>("MyModels", 1, 0, "SalesQueryListModel");
    qmlRegisterType<SalesDocumentsListModel>("MyModels", 1, 0, "SalesDocumentsListModel");
    qmlRegisterType<AccountListModel>("MyModels", 1, 0, "AccountListModel");

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
//    qInstallMessageHandler(customMessageHandler);
#else
    qInstallMsgHandler(customMessageHandler);
#endif

    QmlWin* win = new QmlWin();
    return app.exec();
}

//http://api.erp.slktea.com/isam-web-merchant/auth?account=jinhai&password=e10adc3949ba59abbe56e057f20f883e
