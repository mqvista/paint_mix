#include "service.h"

Service::Service(QObject *parent) : QObject(parent)
{
    //把工作0丢到线程里面
    Worker00::Instance()->moveToThread(&worker00Thread);
    worker00Thread.start();
    QMetaObject::invokeMethod(Worker00::Instance(), "openSerial485", Qt::QueuedConnection);

    //把工作1丢到线程里面，并且初始化开启秤
    Worker01::Instance()->moveToThread(&worker01Thread);
    worker01Thread.start();
    QMetaObject::invokeMethod(Worker01::Instance(), "openScales", Qt::QueuedConnection);

    //链接秤的数值
    connect(Worker01::Instance(), &Worker01::scalesSmallDataChangedSig, Worker00::Instance(), &Worker00::getSmallScalesValue);
    connect(Worker01::Instance(), &Worker01::scalesSmallDataChangedSig, Motion::Instance(), &Motion::getSmallScalesValue);

    connect(Worker01::Instance(), &Worker01::scalesBigDataChangedSig, Worker00::Instance(), &Worker00::getBigScalesValue);
    connect(Worker01::Instance(), &Worker01::scalesBigDataChangedSig, Motion::Instance(), &Motion::getBigScalesValue);

}

Service::~Service()
{
    qDebug() << "emmmmmmm";
    worker00Thread.quit();
    worker00Thread.wait();
    worker01Thread.quit();
    worker01Thread.wait();
}

void Service::closeThread()
{
    //qDebug() << "exiting";
    worker00Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
    worker01Thread.requestInterruption();
    worker00Thread.quit();
    worker00Thread.wait();
}
