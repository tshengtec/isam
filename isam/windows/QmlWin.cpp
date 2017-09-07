#include "QmlWin.h"
#include "Themes.h"
#include "GlobalModel.h"

QmlWin::QmlWin()
{
    this->rootContext()->setContextProperty("themesModel", new Themes());
    this->rootContext()->setContextProperty("globalModel", new GlobalModel());
    this->load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));
}
