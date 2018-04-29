#ifndef GREETER_H
#define GREETER_H

#include <QObject>

class Greeter : public QObject
{
    Q_OBJECT
public:
    explicit Greeter(QObject *parent = nullptr);
    int Add(int a, int b);
signals:

public slots:
};

#endif // GREETER_H
