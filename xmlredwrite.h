#ifndef XMLREDWRITE_H
#define XMLREDWRITE_H

#include <QObject>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QDebug>

class XmlRedWrite : public QObject
{
    Q_OBJECT
public:
    explicit XmlRedWrite(QObject *parent = nullptr);
    bool readConfigXml();
    bool readProfile(QMap<QString, QMap<QString, QString>> &param);
    QMap<QString, QString> readSubProfile(QString name);
    //新增配色方案，值传递QMap
    bool addNewProfile(QMap<QString, QString> conf);
    //覆盖整个配色方案
    bool writeHolyProfile(QMap<QString, QMap<QString, QString>> param);


signals:

public slots:

private:
    QString confPath = "/Users/mqvista/config.xml";
    QString profilePath = "/Users/mqvista/profile.xml";


};

#endif // XMLREDWRITE_H
