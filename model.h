#ifndef MODEL_H
#define MODEL_H

#include <QObject>

class Model : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(double scalesBigValue READ scalesBigValue NOTIFY scalesBigValueChanged)

public:
    explicit Model(QObject *parent = nullptr);
    //scalesBigValue();

signals:
    void scalesBigValueChanged();


public slots:

};

#endif // MODEL_H
