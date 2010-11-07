#include "program.h"

#include "server.h"

Program::Program(QObject *parent) :
    QObject(parent)
{
    Server server;
}
