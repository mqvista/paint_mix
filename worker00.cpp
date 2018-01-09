#include "worker00.h"

Worker00 *Worker00::Instance()
{
    static QMutex mutex;
    static QScopedPointer<Worker00> instance;
    if (Q_UNLIKELY(!instance)) {
        mutex.lock();
        if (!instance) {
            instance.reset(new Worker00);
        }
        mutex.unlock();
    }
    return instance.data();
}

Worker00::Worker00(QObject *parent) : QObject(parent)
{
    DriverGC::Instance()->Open("tty.SLAB_USBtoUART");
}

Worker00::~Worker00()
{

}

void Worker00::motorAction(quint16 boardNum ,quint8 channelNum, qint32 steps)
{
    qDebug() << "Worker00 thread" << QThread::currentThreadId() << endl;
    DriverGC::Instance()->AutoControl_SM_By_Step(boardNum, channelNum, steps);
}

void Worker00::initAsix(quint8 asix)
{
    Motion::Instance()->initAsix(asix);
    qDebug() << "ASIX:" << asix;
}



void Worker00::moveToAsix(quint8 motor)
{
    switch (motor) {
    case 1:
        Motion::Instance()->moveToAsix(Motion::scales1Motor01);
        break;
    case 2:
        Motion::Instance()->moveToAsix(Motion::scales1Motor02);
        break;
    case 3:
        Motion::Instance()->moveToAsix(Motion::scales1Motor03);
        break;
    case 4:
        Motion::Instance()->moveToAsix(Motion::scales1Motor04);
        break;
    case 5:
        Motion::Instance()->moveToAsix(Motion::scales1Motor05);
        break;
    case 6:
        Motion::Instance()->moveToAsix(Motion::scales1Motor06);
        break;
    case 7:
        Motion::Instance()->moveToAsix(Motion::scales1Motor07);
        break;
    case 8:
        Motion::Instance()->moveToAsix(Motion::scales1Motor08);
        break;
    case 9:
        Motion::Instance()->moveToAsix(Motion::scales1Motor09);
        break;
    case 10:
        Motion::Instance()->moveToAsix(Motion::scales1Motor10);
        break;
    default:
        break;
    }
}

void Worker00::runTest()
{
    //Motion::Instance()->moveToAsix(1);
    Motion::Instance()->dropLiquid(1);
}



