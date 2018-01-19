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
                            //读取name部分
                            if (xml.isStartElement() && (xml.name() == "name"))
                            {
                                xml.readNext();
                                profileName = xml.text().toString();
                            }
                            //读取unit和其他部分
                            else if (xml.isStartElement() /*&& (xml.name().mid(0,4) == "Unit")*/)
                            {
                                QString subName;
                                subName = xml.name().toString();
                                xml.readNext();
                                tmp1.insert(subName, xml.text().toString());
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

bool XmlRedWrite::addNewProfile(QMap<QString, QString> conf)
{
    //获取全部配置
    QMap<QString, QMap<QString, QString>> params;
    readProfile(params);
    //判断是重名
    if (params.contains(conf.value("name")))
    {
        return false;
    }
    else
    {
        QString name;
        name = conf.value("name");
        conf.remove("name");
        params.insert(name, conf);
        writeHolyProfile(params);
        return true;
    }
}

bool XmlRedWrite::writeHolyProfile(QMap<QString, QMap<QString, QString> > param)
{
    QFile *file = new QFile(profilePath);
    if (!file->open(QIODevice::WriteOnly))
    {
        qDebug() << "file doesn't access";
        return false;
    }
    else
    {
        QXmlStreamWriter writer(file);
        writer.setAutoFormatting(true); // 自动格式化
        writer.writeStartDocument("1.0", true);  // 开始文档（XML 声明）
        //写paintmix头
        writer.writeStartElement("PaintMix_Profile");

        QMapIterator<QString, QMap<QString, QString>> i(param);
        while (i.hasNext())
        {
            i.next();
            //写单个头formula
            writer.writeStartElement("formula");
            //写name
            writer.writeTextElement("name", i.key());
            QMapIterator<QString, QString> j(i.value());
            while (j.hasNext())
            {
                j.next();
                writer.writeTextElement(j.key(), j.value());
            }
            //写单个尾formula
            writer.writeEndElement();
        }
        //写paintmix尾
        writer.writeEndElement();
        file->close();
        return true;
    }
}


