#include "cppsignalreciver.h"
#include<QDebug>
cppsignalreciver::cppsignalreciver(QObject *parent)
    : QObject{parent}
{}

void cppsignalreciver::qm_ToCpp()
{
    qInfo() << "Hello from CPP Recived from QML";
}
