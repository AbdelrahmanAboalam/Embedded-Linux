#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include<QTimer>

class cppSignalSender : public QObject
{
    Q_OBJECT
public:
    explicit cppSignalSender(QObject *parent = nullptr);

    int value;
    QTimer *timer;
signals:
    void cppToQML(QString value);


};

#endif // CPPSIGNALSENDER_H
