#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QObject>

#define SERVER_IP "192.168.0.3"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);

protected:
     void incomingConnection(int socketDescriptor);
};

#endif // SERVER_H
