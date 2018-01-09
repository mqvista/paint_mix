#include "service.h"

Service::Service(QObject *parent) : QObject(parent)
{
    //把工作0丢到线程里面
//    QThread worker00Thread;
    Worker00::Instance()->moveToThread(&worker00Thread);
    worker00Thread.start();

    //把工作1丢到线程里面，并且初始化开启秤
//    QThread worker01Thread;
    Worker01::Instance()->moveToThread(&worker01Thread);
    worker01Thread.start();
    QMetaObject::invokeMethod(Worker01::Instance(), "openScales", Qt::QueuedConnection);
}

Service::~Service()
{
    qDebug() << "emmmmmmm";
    worker00Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
    worker01Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
}

void Service::closeThread()
{
    qDebug() << "exiting";
    worker00Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
    worker01Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
}
