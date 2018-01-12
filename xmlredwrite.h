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


signals:

public slots:

private:
    QString confPath = "/Users/mqvista/config.xml";
    QString profilePath = "/Users/mqvista/profile.xml";


};

#endif // XMLREDWRITE_H
