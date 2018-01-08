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
    scalesSmall.goToThread(&threadScalesSmall);
    scalesBig.goToThread(&threadScalesBig);

    //链接秤数据信号
    connect(&scalesSmall, &ScalesSmall::receiveDataPush, this, &Worker00::getScalesSmallDataSlot);
    connect(&scalesBig, &ScalesBig::receiveDataPush, this, &Worker00::getScalesBigDataSlot);
    //链接开启信号
    connect(this, &Worker00::scalesSmallOpenSig, &scalesSmall ,&ScalesSmall::scalesOpenSlot);
    connect(this, &Worker00::scalesBigOpenSig, &scalesBig ,&ScalesBig::scalesOpenSlot);
    //链接关闭信号
    connect(this, &Worker00::scalesSmallCloseSig, &scalesSmall ,&ScalesSmall::scalesCloseSlot);
    connect(this, &Worker00::scalesBigCloseSig, &scalesBig ,&ScalesBig::scalesCloseSlot);

    DriverGC::Instance()->Open("tty.SLAB_USBtoUART");

    //emit scalesSmallOpenSig("tty.usbserial", 2400);
    //emit scalesBigOpenSig("tty.usbserial3", 9600);

}

Worker00::~Worker00()
{
    emit scalesSmallCloseSig();
    emit scalesBigCloseSig();
    threadScalesSmall.quit();
    threadScalesBig.quit();
}

void Worker00::getScalesBigDataSlot(double value, QString unit)
{
    m_BigScalesValue = value;
    m_BigScalesUnit = unit;
    emit scalesBigDataChangedSig();
}

void Worker00::getScalesSmallDataSlot(double value, QString unit)
{
    m_SmallScalesValue = value;
    m_SmallScalesUnit = unit;
    emit scalesSmallDataChangedSig();
}

void Worker00::motorAction(quint16 boardNum ,quint8 channelNum, qint32 steps)
{
    DriverGC::Instance()->AutoControl_SM_By_Step(boardNum, channelNum, steps);
}

void Worker00::initAsix(quint8 asix)
{
    Motion::Instance()->initAsix(asix);
    qDebug() << "ASIX:" << asix;
}

double Worker00::getScalesBigValue()
{
    return m_BigScalesValue;
}

double Worker00::getScalesSmallValue()
{
    return m_SmallScalesValue;
}

void Worker00::goToMotor(quint8 motor)
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


