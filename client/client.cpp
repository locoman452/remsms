#include "client.h"

Client::Client(Log * logger, QObject *parent) :
    QThread(parent)
{
    this->logger = logger;

    logger->addMessage("Starting client thread");
    tcpSocket = new QTcpSocket();
    tcpSocket->moveToThread(this);
}

Client::~Client()
{
    logger->addMessage("Destroying thread");
}

void Client::run()
{
    logger->addMessage("Connecting to server");
    tcpSocket->connectToHost("127.0.0.1", 6666);
}
