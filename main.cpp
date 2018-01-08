#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <worker00.h>
#include <QThread>
#include <scalesbig.h>
#include <QQmlContext>
#include <model.h>
#include <QThread>
#include "pagefactorymodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QThread workerThread;
    Worker00::Instance()->moveToThread(&workerThread);
    workerThread.start();
    PageFactoryModel pageFactoryMod;



    engine.rootContext()->setContextProperty("pageFactoryMod", &pageFactoryMod);
    //engine.rootContext()->setContextProperty("worker00", &worker00);       //添加QML上下文



    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    qDebug() << "Main thread" << QThread::currentThreadId() << endl;
    return app.exec();
}
