#include "pagemainmodel.h"

PageMainModel::PageMainModel(QObject *parent) : QObject(parent)
{

}

typedef QMap<QString,QString > aaa;

bool PageMainModel::manualControl(QString yl1, QString yl2, QString yl3, QString yl4, QString yl5, QString yl6, QString yl7, QString sz1, QString zj1, QString zj2, QString water1, QString water2)
{
    struct data
    {
        std::string yl1;
    };

    aaa params;
    params.clear();
    if(yl1 != "")
    {
        params.insert("yl1", yl1);
    }
    if(yl2 != "")
    {
        params.insert("yl2", yl2);
    }
    if(yl3 != "")
    {
        params.insert("yl3", yl3);
    }
    if(yl4 != "")
    {
        params.insert("yl4", yl4);
    }
    if(yl5 != "")
    {
        params.insert("yl5", yl5);
    }
    if(yl6 != "")
    {
        params.insert("yl6", yl6);
    }
    if(yl7 != "")
    {
        params.insert("yl7", yl7);
    }
    if(sz1 != "")
    {
        params.insert("sz1", sz1);
    }
    if(zj1 != "")
    {
        params.insert("zj1", zj1);
    }
    if(zj2 != "")
    {
        params.insert("zj2", zj2);
    }
    if(water1 != "")
    {
        params.insert("water1", water1);
    }
    if(water2 != "")
    {
        params.insert("water2", water2);
    }

//    QMetaObject::invokeMethod(Worker00::Instance()
//                              , "manualControl", Qt::AutoConnection
//                              , Q_ARG(aaa, params));
    return true;
}

bool PageMainModel::getBusy()
{
    return m_isBusy;
}




