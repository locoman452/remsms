#include <QCoreApplication>
#include <QtCore>

#include <stdlib.h>
#include "program.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Program program;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    return a.exec();
}
