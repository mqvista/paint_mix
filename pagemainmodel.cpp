#include "pagemainmodel.h"

PageMainModel::PageMainModel(QObject *parent) : QObject(parent)
{


}

void PageMainModel::runTest()
{
    QMetaObject::invokeMethod(Worker00::Instance(), "runTest", Qt::DirectConnection);
}
