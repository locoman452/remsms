#include "connectionthread.h"

#include <QtNetwork>

ConnectionThread::ConnectionThread(int socketDescriptor, QObject *parent)
    : QThread(parent), socketDescriptor(socketDescriptor)
{
    blockSize = 0;
    tcpSocket = new QTcpSocket(this);

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    SMS sms = smsmanager.fetchSmsById(1);

    printf("%s", sms.message);
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
    xml.clear();
    xml.addData(tcpSocket->readAll());
    this->parseXml();
}

void ConnectionThread::parseXml()
{

}
