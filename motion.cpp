#include "motion.h"

Motion *Motion::Instance()
{
    static QMutex mutex;
    static QScopedPointer<Motion> instance;
    if (Q_UNLIKELY(!instance)) {
        mutex.lock();
        if (!instance) {
            instance.reset(new Motion);
        }
        mutex.unlock();
    }
    return instance.data();
}

Motion::Motion(QObject *parent) : QObject(parent)
{

}

bool Motion::initAsixM0()
{
    //设定A轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CCW, 1);
    //设定A轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(6, 1, DriverGC::StepMotor_CW);
    //设定A轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(6, 1, 5000, 2000);
    //走A轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(6, 1, DriverGC::StepMotor_CCW, 1);
    //清除编码器数值
    DriverGC::Instance()->Setting_Encoder_Zero(6, 2);
    m_currentMotor = 10;
    m_currentDegree = 0;
    return true;
}

//board1 channel1
bool Motion::initAsixM1()
{
    //设定M1轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(1, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(1, 1, DriverGC::StepMotor_CCW, 1);
    //设定M1轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(1, 1, DriverGC::StepMotor_CW);
    //设定M1轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(1, 1, 5000, 2000);
    //走M1轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(1, 1, DriverGC::StepMotor_CCW, 1);
    return true;
}

//board1 channel2
bool Motion::initAsixM2()
{
    //设定M2轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(1, 2, DriverGC::StepMotor_CW, 2);
    DriverGC::Instance()->Setting_Protect_Limit(1, 2, DriverGC::StepMotor_CCW, 3);
    //设定M2轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(1, 2, DriverGC::StepMotor_CW);
    //设定M2轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(1, 2, 5000, 2000);
    //走M2轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(1, 2, DriverGC::StepMotor_CCW, 3);
    return true;
}

//board2 channel1
bool Motion::initAsixM3()
{
    //设定M3轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(2, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(2, 1, DriverGC::StepMotor_CCW, 1);
    //设定M1轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(2, 1, DriverGC::StepMotor_CW);
    //设定M1轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(2, 1, 5000, 2000);
    //走M1轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(2, 1, DriverGC::StepMotor_CCW, 1);
    return true;
}

//board2 channel2
bool Motion::initAsixM4()
{
    //设定M4轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(2, 2, DriverGC::StepMotor_CW, 2);
    DriverGC::Instance()->Setting_Protect_Limit(2, 2, DriverGC::StepMotor_CCW, 3);
    //设定M4轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(2, 2, DriverGC::StepMotor_CW);
    //设定M4轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(2, 2, 5000, 2000);
    //走M4轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(2, 2, DriverGC::StepMotor_CCW, 3);
    return true;
}

//board3 channel1
bool Motion::initAsixM5()
{
    //设定M5轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(3, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(3, 1, DriverGC::StepMotor_CCW, 1);
    //设定M5轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(3, 1, DriverGC::StepMotor_CW);
    //设定M5轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(3, 1, 5000, 2000);
    //走M5轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(3, 1, DriverGC::StepMotor_CCW, 1);
    return true;

}

//board3 channel2
bool Motion::initAsixM6()
{
    //设定M6轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(3, 2, DriverGC::StepMotor_CW, 2);
    DriverGC::Instance()->Setting_Protect_Limit(3, 2, DriverGC::StepMotor_CCW, 3);
    //设定M6轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(3, 2, DriverGC::StepMotor_CW);
    //设定M6轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(3, 2, 5000, 2000);
    //走M6轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(3, 2, DriverGC::StepMotor_CCW, 3);
    return true;

}

//board4 channel1
bool Motion::initAsixM7()
{
    //设定M7轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(4, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(4, 1, DriverGC::StepMotor_CCW, 1);
    //设定M7轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(4, 1, DriverGC::StepMotor_CW);
    //设定M7轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(4, 1, 5000, 2000);
    //走M7轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(4, 1, DriverGC::StepMotor_CCW, 1);
    return true;
}

//board4 channel2
bool Motion::initAsixM8()
{
    //设定M8轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(4, 2, DriverGC::StepMotor_CW, 2);
    DriverGC::Instance()->Setting_Protect_Limit(4, 2, DriverGC::StepMotor_CCW, 3);
    //设定M8轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(4, 2, DriverGC::StepMotor_CW);
    //设定M8轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(4, 2, 5000, 2000);
    //走M8轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(4, 2, DriverGC::StepMotor_CCW, 3);
    return true;

}

//board5 channel1
bool Motion::initAsixM9()
{
    //设定M9轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(5, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(5, 1, DriverGC::StepMotor_CCW, 1);
    //设定M9轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(5, 1, DriverGC::StepMotor_CW);
    //设定M9轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(5, 1, 5000, 2000);
    //走M9轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(5, 1, DriverGC::StepMotor_CCW, 1);
    return true;
}

//board5 channel2
bool Motion::initAsixM10()
{
    //设定M10轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(5, 2, DriverGC::StepMotor_CW, 2);
    DriverGC::Instance()->Setting_Protect_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
    //设定M10轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(5, 2, DriverGC::StepMotor_CW);
    //设定M10轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(5, 2, 5000, 2000);
    //走M10轴的CCW极限
    //DriverGC::Instance()->AutoControl_SM_By_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
    return true;
}

//传参，初始化
bool Motion::initAsix(quint8 motor)
{
    switch (motor)
    {
    case 0:
        initAsixM0();
        return true;
        break;
    case 1:
        initAsixM1();
        return true;
        break;
    case 2:
        initAsixM2();
        return true;
        break;
    case 3:
        initAsixM3();
        return true;
        break;
    case 4:
        initAsixM4();
        return true;
        break;
    case 5:
        initAsixM5();
        return true;
        break;
    case 6:
        initAsixM6();
        return true;
        break;
    case 7:
        initAsixM7();
        return true;
        break;
    case 8:
        initAsixM8();
        return true;
        break;
    case 9:
        initAsixM9();
        return true;
        break;
    case 10:
        initAsixM10();
        return true;
        break;
    default:
        return false;
        break;
    }
}

bool Motion::moveToAsix(quint8 motor)
{
    qint32 tmpSteps;
    if (m_currentDegree > motor)
    {
        tmpSteps = ((m_currentDegree - motor)/36 * 30000) * -1;
        DriverGC::Instance()->AutoControl_SM_By_Step(6, 1, tmpSteps);
        m_currentDegree = motor;
    }
    if (m_currentDegree < motor)
    {
        tmpSteps = ((motor - m_currentDegree)/36 * 30000);
        DriverGC::Instance()->AutoControl_SM_By_Step(6, 1, tmpSteps);
        m_currentDegree = motor;
    }
    if (m_currentDegree == motor)
    {
        return true;
    }
    return true;
}















