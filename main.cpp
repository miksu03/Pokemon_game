#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include "searchablepokemonlistmodel.h"
#include "listfinder.h"

int main(int argc, char *argv[])
{
    //QQuickStyle::setStyle(QLatin1String("Basic"));
    //QQuickStyle::setStyle(QLatin1String("Fusion"));
    QQuickStyle::setStyle(QLatin1String("Imagine"));
    //QQuickStyle::setStyle(QLatin1String("Material"));
    //QQuickStyle::setStyle(QLatin1String("Universal"));
    //QQuickStyle::setStyle(QLatin1String("Windows"));
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    ListFinder myClass;
    qmlRegisterType<SearchablePokemonListModel>("local.pokemonlistmodel", 1, 0, "SearchablePokemonListModel");
    engine.rootContext()->setContextProperty("myClass", &myClass);
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
