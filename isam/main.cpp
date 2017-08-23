#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Themes.h"

#define BACKGROUNDCOLOR "#1f29f9"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    Themes* themes = new Themes();
    themes->setBackgroundColor(BACKGROUNDCOLOR);
    engine.rootContext()->setContextProperty("themesModel", themes);

    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));

    return app.exec();
}
