#include "server.h"

#include <stdlib.h>
#include "connectionthread.h"

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    this->listen(QHostAddress(SERVER_IP), 6666);
}

void Server::incomingConnection(int socketDescriptor)
{
    ConnectionThread * thread = new ConnectionThread(socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
