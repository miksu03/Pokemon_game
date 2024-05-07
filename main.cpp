#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QQmlContext>
#include "searchablepokemonlistmodel.h"
#include "listfinder.h"
#include "userselected.h"
#include <QDebug>
#include "calculations.h"
#include "userpokemon.h"
#include "udpclient.h"

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
    UserSelected userSelection;
    UserPokemon uPokemon;
    Calculations calc;
    qDebug()<<calc.accuracy(100,0,0);
    qDebug()<<calc.attackTime(calc.defaultStatCalculation(100,200),0);
    qDebug()<<calc.attackTime(calc.defaultStatCalculation(100,50),0);
    qDebug()<<calc.damage(95,135,120,100);
    qDebug()<<calc.HP(100,80);
    myClass.myMoveFind("swords-dance");

    qmlRegisterType<UdpClient>("local.udpclient", 1, 0, "UdpClient");
    qmlRegisterType<SearchablePokemonListModel>("local.pokemonlistmodel", 1, 0, "SearchablePokemonListModel");
    engine.rootContext()->setContextProperty("myClass", &myClass);
    engine.rootContext()->setContextProperty("userSelection", &userSelection);
    engine.rootContext()->setContextProperty("uPokmeon", &uPokemon);
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
