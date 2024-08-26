#ifndef CPPSIGNALSENDER_H
#define CPPSIGNALSENDER_H

#include <QObject>
#include <QTimer>

class cppSignalSender : public QObject {
    Q_OBJECT
public:
    explicit cppSignalSender(QObject *parent = nullptr);

public slots:
    void startTimer();
    void stopTimer();

signals:
    void cppToQML(QString value);

private:
    QTimer *timer;
    int value;
};

#endif // CPPSIGNALSENDER_H
