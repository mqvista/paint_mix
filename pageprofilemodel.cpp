#include "pageprofilemodel.h"

PageProfileModel::PageProfileModel(QObject *parent) : QObject(parent)
{

}

QStringList PageProfileModel::getProfileList()
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
    return m_profileList;
    //emit profileListChanged();
}

QVector<QString> PageProfileModel::getSubList()
{
    return m_subList;
}

void PageProfileModel::reflushSubList(QString name)
{
    m_subList.clear();
    XmlRedWrite xmlRedWrite;
    QMap<QString, QString> config;
    config = xmlRedWrite.readSubProfile(name);
    if (config.value("Unit01").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit01").mid(1));
    if (config.value("Unit02").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit02").mid(1));
    if (config.value("Unit03").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit03").mid(1));
    if (config.value("Unit04").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit04").mid(1));
    if (config.value("Unit05").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit05").mid(1));
    if (config.value("Unit06").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit06").mid(1));
    if (config.value("Unit07").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit07").mid(1));
    if (config.value("Unit08").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit08").mid(1));
    if (config.value("Unit09").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit09").mid(1));
    if (config.value("Unit10").isEmpty())
        m_subList.append("-----");
    else
        m_subList.append(config.value("Unit10").mid(1));

    emit subListChanged();
}
