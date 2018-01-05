#include "worker00.h"

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

    //QObject *iteml = en
    //connect()


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

void Worker00::initAsixA()
{
//    for (int i=1; i<7; i++)
//    {
//        DriverGC::Instance()->Special_Reset(i);
//    }
    //16W steps is 90 deg


    //设定A轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CCW, 1);
    //设定A轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(6, 1, DriverGC::StepMotor_CW);
    //设定A轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(6, 1, 5000, 2000);
    //走A轴的CW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(6, 1, DriverGC::StepMotor_CW, 0);
    //走A轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(6, 1, DriverGC::StepMotor_CCW, 1);

}

double Worker00::getScalesBigValue()
{
    return m_BigScalesValue;
}

double Worker00::getScalesSmallValue()
{
    return m_SmallScalesValue;
}


