#include "server.h"

#include <stdlib.h>
#include "connectionthread.h"

Server::Server(Log * logger, QObject *parent)
    : QTcpServer(parent)
{
    logger->addMessage("Starting server");
    this->logger = logger;

    logger->addMessage("Opening tcp socket at 0.0.0.0:6666");

    if(!this->listen(QHostAddress::Any, 6666)){
        logger->addMessage("Tcp socket could not be opened", Log::ERROR);
    }
}

Server::~Server()
{
    logger->addMessage("Closing tcp socket");
}

void Server::incomingConnection(int socketDescriptor)
{
    ConnectionThread * thread = new ConnectionThread(logger, socketDescriptor, this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
