#include "xmlredwrite.h"

XmlRedWrite::XmlRedWrite(QObject *parent) : QObject(parent)
{

}

bool XmlRedWrite::readConfigXml()
{
    QFile *file = new QFile(confPath);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "file doesn't access";
        return false;
    }
    else
    {
        QXmlStreamReader xml(file);
        while (!xml.atEnd())
        {
            xml.readNext();
            //判断是否为paintMix
            if (xml.name() == "PaintMix" && xml.isStartElement())
            {
                while(!xml.atEnd())
                {
                    xml.readNext();

                    if (xml.name() == "scalesSmall" && xml.isStartElement())
                    {
                        while (!(xml.name() == "scalesSmall" && xml.isEndElement()))
                        {
                            xml.readNext();
                            if (xml.isStartElement())
                            {
                                qDebug()<<xml.name();
                                xml.readNext();
                                qDebug()<<xml.text();
                            }
                        }
                    }
                    if (xml.name() == "scalesBig" && xml.isStartElement())
                    {
                        while (!(xml.name() == "scalesBig" && xml.isEndElement()))
                        {
                            xml.readNext();
                            if (xml.isStartElement())
                            {
                                qDebug()<<xml.name();
                                xml.readNext();
                                qDebug()<<xml.text();
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool XmlRedWrite::readProfile(QMap<QString, QMap<QString, QString>>& param)
{
//    QMap<QString, QMap<QString, QString>> profile;
    QFile *file = new QFile(profilePath);
    if (!file->open(QIODevice::ReadOnly))
    {
        qDebug() << "file doesn't access";
        return false;
    }
    else
    {
        QXmlStreamReader xml(file);
        while (!xml.atEnd())
        {
            xml.readNext();
            //判断是否为paintMix
            if (xml.name() == "PaintMix_Profile" && xml.isStartElement())
            {
                while(!xml.atEnd())
                {
                    xml.readNext();
                    if (xml.name() == "formula" && xml.isStartElement())
                    {
                        QString profileName;
                        QMap<QString, QString> tmp1;
                        while (!(xml.name() == "formula" && xml.isEndElement()))
                        {
                            xml.readNext();
                            //读取unit部分
                            if (xml.isStartElement() && (xml.name().mid(0,4) == "Unit"))
                            {
                                QString subName;
                                subName = xml.name().toString();
                                xml.readNext();
                                tmp1.insert(subName, xml.text().toString());
                            }
                            //读取name部分
                            else if (xml.isStartElement() && (xml.name() == "name"))
                            {
                                xml.readNext();
                                profileName = xml.text().toString();
                            }
                        }
//                        profile.insert(profileName, tmp1);
                        param.insert(profileName, tmp1);
                    }
                }
            }
        }
    }
    file->close();
    return true;
}

QMap<QString, QString> XmlRedWrite::readSubProfile(QString name)
{
    //新建找到的配置
    QMap<QString, QString> subParam;
    //获取全部配置
    QMap<QString, QMap<QString, QString>> params;
    readProfile(params);
    subParam = params.value(name);
    return subParam;
}


