#include "pagemainmodel.h"

PageMainModel::PageMainModel(QObject *parent) : QObject(parent)
{


}

void PageMainModel::runTest()
{
    QString a="xxxxx";
    QMetaObject::invokeMethod(Worker00::Instance(), "runFromProfile", Qt::DirectConnection, Q_ARG(QString, a));
}

QStringList PageMainModel::getProfileList()
{
    emit busyChanged();
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
    return m_profileList;
}

QVector<QString> PageMainModel::getSubList()
{
    return m_subList;
}

void PageMainModel::reflushSubList(QString name)
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
        m_subList.append(i.key() + ": " + i.value().mid(1) + "g");
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

void PageMainModel::runFromProfile(QString name)
{
    m_isBusy = true;
    emit busyChanged();
    QMetaObject::invokeMethod(Worker00::Instance(), "runFromProfile", Qt::DirectConnection, Q_ARG(QString, name));
    m_isBusy = false;
    emit busyChanged();
}

bool PageMainModel::getBusy()
{
    return m_isBusy;
}




