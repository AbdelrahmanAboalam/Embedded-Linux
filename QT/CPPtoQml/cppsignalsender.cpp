#include "cppsignalsender.h"

cppSignalSender::cppSignalSender(QObject *parent)
    : QObject{parent}, value(0)
{
    timer= new QTimer (this);

    connect(timer,&QTimer::timeout,[=](){
        ++value; emit cppToQML(QString::number(value)); });

    timer->start(1000);

}
