    #ifndef CONNECTIONTHREAD_H
#define CONNECTIONTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QXmlStreamReader>

#include "smsmanager.h"
#include "log.h"

class ConnectionThread : public QThread
{
    Q_OBJECT
public:
    ConnectionThread(Log * logger, SMSManager * smsManager, int socketDescriptor, QObject *parent);
    ~ConnectionThread();

    void run();

signals:
    void error(QTcpSocket::SocketError socketError);

public slots:
    void readyRead();

private:
    Log * logger;

    void parseXml();

    QTcpSocket *tcpSocket;
    int socketDescriptor;
    QString text;
    QXmlStreamReader xml;

    SMSManager * smsManager;

    quint16 blockSize;
};

#endif // CONNECTIONTHREAD_H
