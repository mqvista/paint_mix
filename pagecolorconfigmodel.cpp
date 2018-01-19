#include "pagecolorconfigmodel.h"

PageColorConfigModel::PageColorConfigModel(QObject *parent) : QObject(parent)
{
    //profileListModel = new QStringListModel();
    //profileListModel->setStringList(getProfileList());
}

void PageColorConfigModel::givePagClrGv(PageColorConfigGridView &pageColorGV)
{
    m_pagClrGv = &pageColorGV;

}

void PageColorConfigModel::reflushSubList(QString name)
{
    m_subList.clear();
    XmlRedWrite xmlRedWrite;
    QMap<QString, QString> config;
    config = xmlRedWrite.readSubProfile(name);
    QMapIterator<QString, QString> i(config);
    while(i.hasNext())
    {
        i.next();
        qDebug()<<i.key();
        m_subList.append(i.key() + ": " + i.value() + " g");
    }
    if (m_subList.length() <9)
    {
        for (int i=0; i<9-m_subList.length(); i++)
        {
            m_subList.append("");
        }
    }
    emit subListChanged();
}

QStringList PageColorConfigModel::getProfileList()
{
    XmlRedWrite xmlRedWrite;
    QMap<QString, QMap<QString, QString>> config;
    if (xmlRedWrite.readProfile(config))
    {
        m_profileList.clear();
        QMapIterator<QString, QMap<QString, QString>> i(config);
        while(i.hasNext())
        {
            i.next();
            m_profileList.append(i.key());
        }
    }
    emit subListChanged();
    return m_profileList;
}

QVector<QString> PageColorConfigModel::getSubList()
{
    return m_subList;
}

QString PageColorConfigModel::getSmallScales()
{
    return m_SmallScalesValue;
}

QString PageColorConfigModel::getBigScales()
{
    return m_BigScalesValue;
}

void PageColorConfigModel::reflushGridView(QString name)
{
    XmlRedWrite xmlRedWrite;
    QMap<QString, QString> config;
    config = xmlRedWrite.readSubProfile(name);
    QMapIterator<QString, QString> i(config);
    m_pagClrGv->removeAll();
    while(i.hasNext())
    {
        i.next();
        qDebug()<<i.key();
        m_pagClrGv->append(PageColorConfigGrid(i.key(), i.value(), "-----"));
    }
}

void PageColorConfigModel::runFromProfile(QString name)
{
    m_isBusy = true;
    emit busyChanged();
    QMetaObject::invokeMethod(Worker00::Instance(), "runFromProfile", Qt::AutoConnection, Q_ARG(QString, name));

    m_isBusy = false;
    emit busyChanged();
}

bool PageColorConfigModel::getBusy()
{
    return m_isBusy;
}

bool PageColorConfigModel::saveNewColorConfig(QString name, QString yl1, QString yl2, QString yl3, QString yl4, QString yl5, QString yl6, QString yl7, QString water1, QString sz1, QString zj1, QString zj2)
{
    XmlRedWrite xmlRedWrite;
    QMap<QString, QString> tmp;
    if (name != "")
    {
        tmp.insert("name", name);
    }
    if (yl1 != "")
    {
        tmp.insert("yl1", yl1);
    }
    if (yl2 != "")
    {
        tmp.insert("yl2", yl2);
    }
    if (yl3 != "")
    {
        tmp.insert("yl3", yl3);
    }
    if (yl4 != "")
    {
        tmp.insert("yl4", yl4);
    }
    if (yl5 != "")
    {
        tmp.insert("yl5", yl5);
    }
    if (yl6 != "")
    {
        tmp.insert("yl6", yl6);
    }
    if (yl7 != "")
    {
        tmp.insert("yl7", yl7);
    }
    if (water1 != "")
    {
        tmp.insert("water1", water1);
    }
    if (sz1 != "")
    {
        tmp.insert("sz1", sz1);
    }
    if (zj1 != "")
    {
        tmp.insert("zj1", zj1);
    }
    if (zj2 != "")
    {
        tmp.insert("zj2", zj2);
    }
    return xmlRedWrite.addNewProfile(tmp);
    if (xmlRedWrite.addNewProfile(tmp))
    {
        emit profileListChanged();
        return true;
    }
}

void PageColorConfigModel::getSmallScalesValue(double value)
{
    m_SmallScalesValue = QString::number(value, 10, 2);
    emit smallScalesChanged();
}

void PageColorConfigModel::getBigScalesValue(double value)
{
    m_BigScalesValue = QString::number(value, 10, 2);
    emit bigScalesChanged();
}
