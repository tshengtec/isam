#include "QmlWin.h"

QmlWin::QmlWin()
{
    this->load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));
}
