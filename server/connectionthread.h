#ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QXmlStreamReader>

#include "smsmanager.h"

class ConnectionThread : public QThread
{
    Q_OBJECT
public:
    ConnectionThread(int socketDescriptor, QObject *parent);

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();

private:
    void parseXml();

    QTcpSocket *tcpSocket;
    int socketDescriptor;
    QString text;
    QXmlStreamReader xml;

    SMSManager smsmanager;

    quint16 blockSize;
};

#endif // CONNECTIONTHREAD_H
