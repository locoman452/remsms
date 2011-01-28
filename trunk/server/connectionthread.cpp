#include "connectionthread.h"

#include <QtNetwork>

ConnectionThread::ConnectionThread(Log * logger, SMSManager * smsManager, int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
    this->logger = logger;
    this->smsManager = smsManager;

    blockSize = 0;
    tcpSocket = new QTcpSocket();
    tcpSocket->moveToThread(this);

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    logger->addMessage("New connection started (" + QString::number(socketDescriptor) + ")");
}

ConnectionThread::~ConnectionThread()
{
    logger->addMessage("Connection closed (" + QString::number(this->socketDescriptor) + ")");

}

void ConnectionThread::run()
{
    if (!tcpSocket->setSocketDescriptor(socketDescriptor)) {
        emit error(tcpSocket->error());
        return;
    }
}

void ConnectionThread::readyRead()
{
    logger->addMessage("New data received");
    xml.clear();
    xml.addData(tcpSocket->readAll());
    this->parseXml();
}

void ConnectionThread::parseXml()
{
    logger->addMessage("Parsing data");
}
