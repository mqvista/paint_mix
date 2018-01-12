#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QThread>
#include <QQmlContext>
#include <QMetaObject>

#include <scalesbig.h>

#include "service.h"
#include "pagefactorymodel.h"
#include "pagemainmodel.h"
#include "pageprofilemodel.h"
#include "pagesidebarmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    Service service;
    QObject::connect(&engine, &QQmlApplicationEngine::quit, &service, &Service::closeThread);

    //实例化页面服务对象
    PageFactoryModel pageFactoryMod;
    PageMainModel pageMainModel;
    PageProfileModel pageProfileModel;
    PageSideBarModel pageSideBarModel;


    engine.rootContext()->setContextProperty("pageFactoryMod", &pageFactoryMod);
    engine.rootContext()->setContextProperty("pageMainModel", &pageMainModel);
    engine.rootContext()->setContextProperty("pageProfileModel", &pageProfileModel);
    engine.rootContext()->setContextProperty("pageSideBarModel", &pageSideBarModel);

    //连接秤信号到sidebar
    QObject::connect(Worker01::Instance(), &Worker01::scalesSmallDataChangedSig, &pageSideBarModel, &PageSideBarModel::getSmallScalesValue);
    //QObject::connect(Worker01::Instance(), &Worker01::scalesBigDataChangedSig, &pageSideBar, &PageSideBar::getBigScalesValue);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    qDebug() << "Main thread" << QThread::currentThreadId() << endl;
    return app.exec();
}
