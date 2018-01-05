#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <worker00.h>
#include <QThread>
#include <scalesbig.h>
#include <QQmlContext>
#include <model.h>
#include <QThread>
#include "pagetestmode.h"
#include "pagefactorymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    //qmlRegisterType<PageTestMode>("Pages", 1, 0, "PageTestModel");
    QQmlApplicationEngine engine;

    Worker00 worker00;
    QThread workerThread;
    worker00.moveToThread(&workerThread);
    workerThread.start();

    PageFactoryModel pageFactoryMod;


   // qmlRegisterType<QBitArray>("Qlist2s",1,0,"QBitArray");

    engine.rootContext()->setContextProperty("pageFactoryMod", &pageFactoryMod);
    engine.rootContext()->setContextProperty("worker00", &worker00);       //添加QML上下文



    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    //QObject * text_Msg = engine.rootObjects()[0]->findChild<QObject*>("recLim1");
    //qDebug() << "sth:" << text_Msg;

    //QObject *rootObject = engine.rootObjects().first();
    //QObject *qmlObject = rootObject->findChild<QObject*>("recLim1");
    //qmlObject->setProperty("visible", true);

    /*********/
    qDebug() << "Main thread" << QThread::currentThreadId() << endl;
    /*********/
    return app.exec();
}
