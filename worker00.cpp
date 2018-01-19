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

}

Worker00::~Worker00()
{
    //closeSerial485();
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

void Worker00::moveToAsixBig(quint8 motor)
{
    switch (motor) {
    case 1:
        Motion::Instance()->moveToAsix(Motion::scales2Motor01);
        break;
    case 2:
        Motion::Instance()->moveToAsix(Motion::scales2Motor02);
        break;
    case 3:
        Motion::Instance()->moveToAsix(Motion::scales2Motor03);
        break;
    case 4:
        Motion::Instance()->moveToAsix(Motion::scales2Motor04);
        break;
    case 5:
        Motion::Instance()->moveToAsix(Motion::scales2Motor05);
        break;
    case 6:
        Motion::Instance()->moveToAsix(Motion::scales2Motor06);
        break;
    case 7:
        Motion::Instance()->moveToAsix(Motion::scales2Motor07);
        break;
    case 8:
        Motion::Instance()->moveToAsix(Motion::scales2Motor08);
        break;
    case 9:
        Motion::Instance()->moveToAsix(Motion::scales2Motor09);
        break;
    case 10:
        Motion::Instance()->moveToAsix(Motion::scales2Motor10);
        break;
    default:
        break;
    }
}

void Worker00::runTest()
{
    //Motion::Instance()->dropLiquid(1, 5);
    runFromProfile("xxxxx");
}

void Worker00::runFromProfile(QString name)
{
    XmlRedWrite xmlRedWrite;
    //获取全部配置
    QMap<QString, QMap<QString, QString>> params;
    xmlRedWrite.readProfile(params);
    //新建找到的配置
    QMap<QString, QString> param;
    param = params.value(name);

    qDebug()<<param;
    //使用map迭代器
    QMapIterator<QString, QString> i(param);
    while(i.hasNext())
    {
        i.next();
        if (i.key().mid(0,2) == "yl")
        {
            quint8 motor = i.key().mid(2).toInt();
            quint16 weight = i.value().toInt();
            Worker00::Instance()->moveToAsix(motor);
            Motion::Instance()->dropLiquid(motor, weight);
        }
        if (i.key().mid(0,2) == "sz")
        {
            quint8 motor = 8;
            quint16 weight = i.value().toInt();
            Worker00::Instance()->moveToAsixBig(motor);
            Motion::Instance()->dropLiquid(motor, weight);
        }
        if (i.key().mid(0,2) == "zj")
        {
            quint8 motor;
            if (i.key().mid(2).toInt() == 1)
            {
                motor = 9;
            }
            else
            {
                motor = 10;
            }
            quint16 weight = i.value().toInt();
            Worker00::Instance()->moveToAsix(motor);
            Motion::Instance()->dropLiquid(motor, weight);
        }
        if (i.key().mid(0,5) == "water")
        {
            quint32 ch = i.key().mid(5, 1).toInt();
            quint32 weight = i.value().toInt();
            Motion::Instance()->addWater(ch, weight);
        }
    }
    Motion::Instance()->moveSmallScalesWaterToBigScalles();
}



void Worker00::manualControl(QStringList params)
{
    if (params.at(0) !="")
    {
        quint16 weight = params.at(0).toInt();
        Worker00::Instance()->moveToAsix(1);
        Motion::Instance()->dropLiquid(1, weight);
    }
    if (params.at(0) !="")
    {
        quint16 weight = params.at(0).toInt();
        Worker00::Instance()->moveToAsix(1);
        Motion::Instance()->dropLiquid(1, weight);
    }




//    QMapIterator<QString, QString> i(params);
//    while(i.hasNext())
//    {
//        i.next();
//        if (i.key().mid(0,2) == "yl")
//        {
//            quint8 motor = i.key().mid(2).toInt();
//            quint16 weight = i.value().toInt();
//            Worker00::Instance()->moveToAsix(motor);
//            Motion::Instance()->dropLiquid(motor, weight);
//        }
//        if (i.key().mid(0,2) == "sz")
//        {
//            quint8 motor = 8;
//            quint16 weight = i.value().toInt();
//            Worker00::Instance()->moveToAsixBig(motor);
//            Motion::Instance()->dropLiquid(motor, weight);
//        }
//        if (i.key().mid(0,2) == "zj")
//        {
//            quint8 motor;
//            if (i.key().mid(2).toInt() == 1)
//            {
//                motor = 9;
//            }
//            else
//            {
//                motor = 10;
//            }
//            quint16 weight = i.value().toInt();
//            Worker00::Instance()->moveToAsix(motor);
//            Motion::Instance()->dropLiquid(motor, weight);
//        }
//        if (i.key().mid(0,5) == "water")
//        {
//            quint32 ch = i.key().mid(5, 1).toInt();
//            quint32 weight = i.value().toInt();
//            Motion::Instance()->addWater(ch, weight);
//        }
//    }
    Motion::Instance()->moveSmallScalesWaterToBigScalles();
}

void Worker00::openSerial485()
{
    DriverGC::Instance()->Open("tty.SLAB_USBtoUART");
}

void Worker00::closeSerial485()
{
    DriverGC::Instance()->Close();
}

void Worker00::initSystem()
{
    //初始化A轴
    initAsix(0);
}

void Worker00::getSmallScalesValue(double value)
{
    m_SmallScalesValue = value;
}

void Worker00::getBigScalesValue(double value)
{
    m_BigScalesValue = value;
}

