#include "scales.h"


Scales::Scales(QObject *parent) : QObject(parent)
{
    //连接串口接受信号
    connect(&serial_port, &QSerialPort::readyRead, this, &Scales::rawSerialReceiveSlot);
}

void Scales::open(QString port, quint32 baud)
{
    qDebug() << "Scales thread:" << QThread::currentThreadId() <<endl;

    serial_port.setPortName(port);
    if (serial_port.open(QIODevice::ReadWrite))         //打开端口
    {
        qDebug() << "serial is opened " << endl;
        serial_port.setBaudRate(baud);
        serial_port.setDataBits(QSerialPort::Data8);
        serial_port.setParity(QSerialPort::NoParity);
        serial_port.setStopBits(QSerialPort::OneStop);
        serial_port.setFlowControl(QSerialPort::NoFlowControl);
        serial_port.clearError();
        serial_port.clear();
    }
    else
    {
        qDebug() << "Open Failed";
    }
}

void Scales::close()
{
    serial_port.close();
}

void Scales::goToThread(QThread *thread)
{
    serial_port.moveToThread(thread);
    this->moveToThread(thread);
    thread->start();
}


void Scales::rawSerialReceiveSlot()
{
    QByteArray readAllData = serial_port.readAll();     //读取收到的数据one Byte
    //static QString receivedata;                         //生成 static QString变量
    receivedata.append(readAllData.data());             //将QByteArray转为QString，并保存

    if (QString(readAllData.data()) == "\n") {
        m_receivedata = receivedata;
        //qDebug() << "Serial is received" << receivedata << endl;
        receivedata.clear();
        serialStrConver2Data(m_receivedata);
        emit receiveDataPush(m_scalesValue, m_scalesUnit);
    }
}

void Scales::scalesOpenSlot(QString port, quint32 baud)
{
    open(port, baud);
}

void Scales::scalesCloseSlot()
{
    close();
}
