#include <QCoreApplication>
#include <QtCore>

#include <stdlib.h>
#include "program.h"
#include "log.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Log * logger = new Log(true, "C:\\Users\\Eric Lembregts\\Documents\\log.txt");
    logger->addMessage("Logging started");

    Program *program = new Program(logger, &a);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    return a.exec();
}
