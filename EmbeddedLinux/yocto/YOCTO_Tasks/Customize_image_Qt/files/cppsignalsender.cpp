#include "cppsignalsender.h"


cppSignalSender::cppSignalSender(QObject *parent)
    : QObject{parent}, value(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() {
        ++value;
        emit cppToQML(QString::number(value));
    });
}

void cppSignalSender::startTimer() {
    if (!timer->isActive()) {
        timer->start(1000);
    }
}

void cppSignalSender::stopTimer() {
    if (timer->isActive()) {
        timer->stop();
    }
}
