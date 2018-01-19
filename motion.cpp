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

Motion::Motion()
{

}

void Motion::getSmallScalesValue(double value)
{
    m_SmallScalesValue = value;
}

void Motion::getBigScalesValue(double value)
{
    m_BigScalesValue = value;
}

bool Motion::initAsixM0()
{
    //设定A轴的限位通道
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CW, 0);
    DriverGC::Instance()->Setting_Protect_Limit(6, 1, DriverGC::StepMotor_CCW, 1);
    //设定A轴的运动方向
    DriverGC::Instance()->Setting_SM_RelDir(6, 1, DriverGC::StepMotor_CW);
    //设定A轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(6, 1, 20000, 60000);
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
    DriverGC::Instance()->Setting_SM_Speed(1, 1, 2500, 8000);
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
    DriverGC::Instance()->Setting_SM_Speed(1, 2, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(2, 1, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(2, 2, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(3, 1, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(3, 2, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(4, 1, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(4, 2, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_Speed(5, 1, 6000, 18000);
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
    DriverGC::Instance()->Setting_SM_RelDir(5, 2, DriverGC::StepMotor_CCW);
    //设定M10轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(5, 2, 8000, 18000);
    //走M10轴的CCW极限
    DriverGC::Instance()->AutoControl_SM_By_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
    return true;
}

//board6 channel2
bool Motion::initAsixM11()
{
    //设定M10轴的限位通道
    //DriverGC::Instance()->Setting_Protect_Limit(6, 2, DriverGC::StepMotor_CW, 2);
    //DriverGC::Instance()->Setting_Protect_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
    //设定M10轴的运动方向
    //DriverGC::Instance()->Setting_SM_RelDir(5, 2, DriverGC::StepMotor_CCW);
    //设定M10轴的默认运动速度
    DriverGC::Instance()->Setting_SM_Speed(6, 2, 2000, 6000);
    //走M10轴的CCW极限
    //DriverGC::Instance()->AutoControl_SM_By_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
    return true;
}

//传参，初始化轴
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
    case 11:
        initAsixM11();
        return true;
        break;
    default:
        return false;
        break;
    }
}

bool Motion::moveToAsix(quint16 motor)
{
    //288000/10
    //28800
    qint32 tmpSteps;
    if (m_currentDegree > motor)
    {
        tmpSteps = ((m_currentDegree - motor)/36 * (28800<<2)) * -1;
        qDebug() << "Steps->" << tmpSteps;
        DriverGC::Instance()->AutoControl_SM_By_Step(6, 1, tmpSteps);
        m_currentDegree = motor;
        qDebug() << "Am_currentDegree->" << m_currentDegree;
        waitWhileFree(11);
    }
    if (m_currentDegree < motor)
    {
        tmpSteps = ((motor - m_currentDegree)/36 * (28800<<2));
        qDebug() << "Steps->" << tmpSteps;
        DriverGC::Instance()->AutoControl_SM_By_Step(6, 1, tmpSteps);
        m_currentDegree = motor;
        qDebug() << "Bm_currentDegree->" << m_currentDegree;
        waitWhileFree(11);
    }
    if (m_currentDegree == motor)
    {
        return true;
    }
    return true;
}

bool Motion::dropLiquid(quint8 motor, quint16 weight)
{
    //设定循环标志
    m_asixMoveState = true;
    switch (motor)
    {
    case 1:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(1, lims);
            //在限位就上升
            if (lims[1] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(1, 1, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(1, 1, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(1, 1, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(1, 1, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(1, 1, DriverGC::StepMotor_CCW, 1);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(1, 1, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(1, 1, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(1, 1, DriverGC::StepMotor_CCW, 1);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(1, 1, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(1);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(1, 1, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(1, 1, 2000);
                    }
                }
            }
            else
            {
                stopDrop(1);
            }
        }
        return true;
        break;
    }
    case 2:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(1, lims);
            //在限位就上升
            if (lims[3] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(1, 2, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(1, 2, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(1, 2, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(1, 2, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(1, 2, DriverGC::StepMotor_CCW, 3);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(1, 2, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(1, 2, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(1, 2, DriverGC::StepMotor_CCW, 3);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(1, 2, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(2);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(1, 2, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(1, 2, 2000);
                    }
                }
            }
            else
            {
                stopDrop(2);
            }
        }
        return true;
        break;
    }
    case 3:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(2, lims);
            //在限位就上升
            if (lims[1] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(2, 1, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(2, 1, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(2, 1, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(2, 1, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(2, 1, DriverGC::StepMotor_CCW, 1);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(2, 1, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(2, 1, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(2, 1, DriverGC::StepMotor_CCW, 1);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(2, 1, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(3);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(2, 1, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(2, 1, 2000);
                    }
                }
            }
            else
            {
                stopDrop(3);
            }
        }
        return true;
        break;
    }
    case 4:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(2, lims);
            //在限位就上升
            if (lims[3] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(2, 2, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(2, 2, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(2, 2, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(2, 2, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(2, 2, DriverGC::StepMotor_CCW, 3);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(2, 2, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(2, 2, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(2, 2, DriverGC::StepMotor_CCW, 3);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(2, 2, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(4);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(2, 2, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(2, 2, 2000);
                    }
                }
            }
            else
            {
                stopDrop(4);
            }
        }
        return true;
        break;
    }
    case 5:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(3, lims);
            //在限位就上升
            if (lims[1] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(3, 1, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(3, 1, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(3, 1, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(3, 1, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(3, 1, DriverGC::StepMotor_CCW, 1);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(3, 1, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(3, 1, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(3, 1, DriverGC::StepMotor_CCW, 1);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(3, 1, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(5);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(3, 1, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(3, 1, 2000);
                    }
                }
            }
            else
            {
                stopDrop(5);
            }
        }
        return true;
        break;
    }
    case 6:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(3, lims);
            //在限位就上升
            if (lims[3] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(3, 2, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(3, 2, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(3, 2, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(3, 2, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(3, 2, DriverGC::StepMotor_CCW, 3);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(3, 2, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(3, 2, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(3, 2, DriverGC::StepMotor_CCW, 3);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(3, 2, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(6);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(3, 2, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(3, 2, 2000);
                    }
                }
            }
            else
            {
                stopDrop(6);
            }
        }
        return true;
        break;
    }
    case 7:
    {
        double oldWeight = m_SmallScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(4, lims);
            //在限位就上升
            if (lims[1] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(4, 1, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(4, 1, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(4, 1, a);
                    msleep(100);
                }
            }
            //高速档
            if (oldWeight+weight-m_SmallScalesValue >3)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(4, 1, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(4, 1, DriverGC::StepMotor_CCW, 1);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(4, 1, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_SmallScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(4, 1, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(4, 1, DriverGC::StepMotor_CCW, 1);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(4, 1, b);
                    msleep(50);
                    if (m_SmallScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(7);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(4, 1, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(4, 1, 2000);
                    }
                }
            }
            else
            {
                stopDrop(7);
            }
        }
        return true;
        break;
    }
    case 8:
    {
        double oldWeight = m_BigScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(4, lims);
            //在限位就上升
            if (lims[3] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(4, 2, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(4, 2, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(4, 2, a);
                    msleep(100);
                }
            }
            //中速档
            if (oldWeight+weight-m_BigScalesValue >1.5)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(4, 2, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(4, 2, DriverGC::StepMotor_CCW, 3);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(4, 2, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_BigScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(4, 2, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(4, 2, DriverGC::StepMotor_CCW, 3);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(4, 2, b);
                    msleep(50);
                    if (m_BigScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(8);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(4, 2, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(4, 2, 2000);
                    }
                }
            }
            else
            {
                stopDrop(8);
            }
        }
        return true;
        break;
    }
    case 9:
    {
        double oldWeight = m_BigScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(5, lims);
            //在限位就上升
            if (lims[1] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(5, 1, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(5, 1, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(5, 1, a);
                    msleep(100);
                }
            }
            //中速档
            if (oldWeight+weight-m_BigScalesValue >1.5)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(5, 1, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(5, 1, DriverGC::StepMotor_CCW, 1);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(5, 1, b);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_BigScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(5, 1, 300, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(5, 1, DriverGC::StepMotor_CCW, 1);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(5, 1, b);
                    msleep(50);
                    if (m_BigScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(9);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(5, 1, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(5, 1, 2000);
                    }
                }
            }
            else
            {
                stopDrop(9);
            }
        }
        return true;
        break;
    }
    case 10:
    {
        double oldWeight = m_BigScalesValue;
        while (m_asixMoveState) {
            //先查询是否在限位极限
            QBitArray lims;
            DriverGC::Instance()->Inquire_Limit(5, lims);
            //在限位就上升
            if (lims[3] == 1)
            {
                //快速上升
                DriverGC::Instance()->Setting_SM_Speed(5, 2, 8000, 18000);
                DriverGC::Instance()->AutoControl_SM_By_Step(5, 2, 10000);
                //查询限位是否在忙
                bool a=true;
                while(a)
                {
                    DriverGC::Instance()->Inquire_Status(5, 2, a);
                    msleep(100);
                }
            }
            //中速档
            if (oldWeight+weight-m_BigScalesValue >1.5)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(5, 2, 4000, 12000);
                DriverGC::Instance()->AutoControl_SM_By_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
                bool b = true;
                //等待任务完成
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(5, 2, b);
                    //msleep(50);
                    msleep(50);
                }
                continue;
            }
            //低速挡
            if (m_BigScalesValue-oldWeight < weight)
            {
                //设定慢速注射
                DriverGC::Instance()->Setting_SM_Speed(5, 2, 400, 1200);
                DriverGC::Instance()->AutoControl_SM_By_Limit(5, 2, DriverGC::StepMotor_CCW, 3);
                //查询是否在自动控制
                bool b = true;
                while(b)
                {
                    DriverGC::Instance()->Inquire_Status(5, 2, b);
                    msleep(50);
                    if (m_BigScalesValue-oldWeight >= weight)
                    {
                        b = false;
                        stopDrop(10);
                        //高速回抽
                        DriverGC::Instance()->Setting_SM_Speed(5, 2, 8000, 18000);
                        DriverGC::Instance()->AutoControl_SM_By_Step(5, 2, 2000);
                    }
                }
            }
            else
            {
                stopDrop(10);
            }
        }
        return true;
        break;
    }
    default:
    {
        return false;
        break;
    }
    }
}

bool Motion::stopDrop(quint8 motor)
{
    m_asixMoveState = false;
    switch (motor) {
    case 1:
        DriverGC::Instance()->Control_SM(1, 1, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 2:
        DriverGC::Instance()->Control_SM(1, 2, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 3:
        DriverGC::Instance()->Control_SM(2, 1, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 4:
        DriverGC::Instance()->Control_SM(2, 2, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 5:
        DriverGC::Instance()->Control_SM(3, 1, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 6:
        DriverGC::Instance()->Control_SM(3, 2, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 7:
        DriverGC::Instance()->Control_SM(4, 1, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 8:
        DriverGC::Instance()->Control_SM(4, 2, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 9:
        DriverGC::Instance()->Control_SM(5, 1, DriverGC::StepMotor_Stop);
        return true;
        break;
    case 10:
        DriverGC::Instance()->Control_SM(5, 2, DriverGC::StepMotor_Stop);
        return true;
        break;
    default:
        return false;
        break;
    }
}

bool Motion::addWater(quint8 scalesNum, quint16 weight)
{
    QBitArray sta(24);
    double oldWeight;
    bool a;
    switch (scalesNum) {
    case 1:
        sta.fill(false);
        sta.setBit(0);
        oldWeight = m_SmallScalesValue;
        DriverGC::Instance()->Control_ValveOpen(6, sta);
        DriverGC::Instance()->Control_Motor(6,10000);

        a = true;
        while (a)
        {

            if (m_SmallScalesValue - oldWeight >= weight)
            {
                a =false;
                DriverGC::Instance()->Control_ValveClose(6, sta);
                DriverGC::Instance()->Control_Motor(6,0);
            }
            msleep(100);
        }
        return true;
        break;
    case 2:
        sta.fill(false);
        sta.setBit(1);
        oldWeight = m_BigScalesValue;
        DriverGC::Instance()->Control_ValveOpen(6, sta);
        DriverGC::Instance()->Control_Motor(6,10000);
        a = true;
        while (a)
        {

            if (m_BigScalesValue - oldWeight >= weight)
            {
                a =false;
                DriverGC::Instance()->Control_ValveClose(6, sta);
                DriverGC::Instance()->Control_Motor(6,0);
            }
            msleep(100);
        }
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

void Motion::waitWhileFree(quint16 motor)
{
    bool state = true;
    switch (motor) {
    case 1:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(1, 1, state);
            msleep(500);
        }
        break;
    case 2:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(1, 2, state);
            msleep(500);
        }
        break;
    case 3:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(2, 1, state);
            msleep(500);
        }
        break;
    case 4:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(2, 2, state);
            msleep(500);
        }
        break;
    case 5:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(3, 1, state);
            msleep(500);
        }
        break;
    case 6:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(3, 2, state);
            msleep(500);
        }
        break;
    case 7:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(4, 1, state);
            msleep(500);
        }
        break;
    case 8:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(4, 2, state);
            msleep(500);
        }
        break;
    case 9:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(5, 1, state);
            msleep(500);
        }
        break;
    case 10:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(5, 2, state);
            msleep(500);
        }
        break;
    case 11:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(6, 1, state);
            msleep(500);
        }
        break;
    case 12:
        while (state)
        {
            DriverGC::Instance()->Inquire_Status(6, 2, state);
            msleep(500);
        }
        break;
    default:
        break;
    }

}

bool Motion::getBusyStatus()
{
    return m_isBusy;
}

bool Motion::moveSmallScalesWaterToBigScalles()
{
    DriverGC::Instance()->Setting_SM_Speed(6, 2, 4000, 12000);
    bool a=true;
    double oldWeight = m_SmallScalesValue;
    DriverGC::Instance()->Control_SM(6, 2, DriverGC::StepMotor_CW);
    //如果变化率小于1g，则停止
    while (a)
    {
        sleep(2);
        if (oldWeight-m_SmallScalesValue <= 1)
        {
            a = false;
            DriverGC::Instance()->Control_SM(6, 2, DriverGC::StepMotor_Stop);
        }
        oldWeight = m_SmallScalesValue;

    }
    return true;
}










