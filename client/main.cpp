#include <QtGui/QApplication>
#include "mainwindow.h"

#include "log.h"
#include "client.h"

int main(int argc, char *argv[])
{
    Log * logger = new Log(true, "log.txt");
    QApplication a(argc, argv);

    Client * client = new Client(logger, &a);
    client->start();

    MainWindow w;
    w.show();

    return a.exec();
}
