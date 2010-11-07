#ifndef SMSMANAGER_H
#define SMSMANAGER_H

#include <QString>
#include <QSqlDatabase>
#include <QList>

typedef struct {
    QString smsid;
    QString from;
    QString to;
    QString date;
    QString message;
} SMS;

class SMSManager
{
public:
    SMSManager();

    void insertSms(SMS sms);
    void updateSms(int smsid, SMS sms);
    void deleteSms(int smsid);
    SMS fetchSmsById(int smsid);
    QList<SMS> fetchAllSms();

private:
    QString phonenumber;
    QString usertoken;
    QString clienttoken;
    QSqlDatabase db;
};

#endif // SMSMANAGER_H
