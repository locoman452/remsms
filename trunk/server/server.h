#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>

#include "log.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(Log * logger, QObject *parent = 0);
    ~Server();

protected:
     void incomingConnection(int socketDescriptor);

private:
     Log * logger;
};

#endif // SERVER_H
