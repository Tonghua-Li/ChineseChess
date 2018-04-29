#include "Greeter.h"

Greeter::Greeter(QObject *parent) : QObject(parent)
{

}

int Greeter::Add(int a, int b)
{
    return a + b;
}
