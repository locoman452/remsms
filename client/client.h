#ifndef CLIENT_H
#define CLIENT_H

#include <QThread>
#include <QTcpSocket>

#include "log.h"

class Client : public QThread
{
    Q_OBJECT
public:
    explicit Client(Log * logger, QObject *parent = 0);
    ~Client();

    void run();

signals:

public slots:

private:
    Log * logger;

    QTcpSocket * tcpSocket;

};

#endif // CLIENT_H
