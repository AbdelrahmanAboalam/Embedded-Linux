#ifndef CPPSIGNALRECIVER_H
#define CPPSIGNALRECIVER_H

#include <QObject>

class cppsignalreciver : public QObject
{
    Q_OBJECT
public:
    explicit cppsignalreciver(QObject *parent = nullptr);

public slots:
    void qm_ToCpp();
signals:


};

#endif // CPPSIGNALRECIVER_H
