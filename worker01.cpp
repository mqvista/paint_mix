#include "worker01.h"

Worker01 *Worker01::Instance()
{
    static QMutex mutex;
    static QScopedPointer<Worker01> instance;
    if (Q_UNLIKELY(!instance)) {
        mutex.lock();
        if (!instance) {
            instance.reset(new Worker01);
        }
        mutex.unlock();
    }
    return instance.data();
}

Worker01::~Worker01()
{
    emit scalesSmallCloseSig();
    emit scalesBigCloseSig();
    threadScalesSmall.quit();
    threadScalesBig.quit();
}

Worker01::Worker01(QObject *parent) : QObject(parent)
{
    scalesSmall.goToThread(&threadScalesSmall);
    scalesBig.goToThread(&threadScalesBig);
    //链接秤数据信号
    connect(&scalesSmall, &ScalesSmall::receiveDataPush, this, &Worker01::getScalesSmallDataSlot);
    connect(&scalesBig, &ScalesBig::receiveDataPush, this, &Worker01::getScalesBigDataSlot);
    //链接秤开启信号
    connect(this, &Worker01::scalesSmallOpenSig, &scalesSmall ,&ScalesSmall::scalesOpenSlot);
    connect(this, &Worker01::scalesBigOpenSig, &scalesBig ,&ScalesBig::scalesOpenSlot);
    //链接秤关闭信号
    connect(this, &Worker01::scalesSmallCloseSig, &scalesSmall ,&ScalesSmall::scalesCloseSlot);
    connect(this, &Worker01::scalesBigCloseSig, &scalesBig ,&ScalesBig::scalesCloseSlot);
}

void Worker01::openScales()
{
    emit scalesSmallOpenSig("tty.usbserial", 2400);
    //emit scalesBigOpenSig("tty.usbserial24", 9600);
}

void Worker01::closeScales()
{
    emit scalesSmallCloseSig();
    emit scalesBigCloseSig();
}

void Worker01::getScalesBigDataSlot(double value, QString unit)
{
    m_BigScalesValue = value;
    m_BigScalesUnit = unit;
    emit scalesBigDataChangedSig(m_BigScalesValue);
}

void Worker01::getScalesSmallDataSlot(double value, QString unit)
{
    m_SmallScalesValue = value;
    m_SmallScalesUnit = unit;
    emit scalesSmallDataChangedSig(m_SmallScalesValue);
}

double Worker01::getScalesBigValue()
{
    return m_BigScalesValue;
}

double Worker01::getScalesSmallValue()
{
    return m_SmallScalesValue;
}
