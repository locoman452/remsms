#ifndef PROGRAM_H
#define PROGRAM_H

#include <QThread>

#include "server.h"
#include "log.h"

class Program : public QThread
{
    Q_OBJECT
public:
    Program(Log * logger, QObject *parent = 0);

signals:

public slots:

private:
    Server * server;
    Log * logger;

};

#endif // PROGRAM_H
