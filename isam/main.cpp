#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "Themes.h"

#define BACKGROUNDCOLOR "lightblue"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    Themes* themes = new Themes();
    themes->setBackgroundColor(QString("lightblue"));
    engine.rootContext()->setContextProperty("themesModel", themes);

    engine.load(QUrl(QStringLiteral("qrc:/qml/MainWin/MainWin.qml")));

    return app.exec();
}
