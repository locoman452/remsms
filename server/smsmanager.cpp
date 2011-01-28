#include "smsmanager.h"

#include <QSqlQuery>
#include <QVariant>
#include <QString>

SMSManager::SMSManager()
{
    if(!db.isOpen()){
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("localhost");
        db.setDatabaseName("remsms");
        db.setUserName("remsms");
        db.setPassword("remsms");
        db.open();
    }
}

void SMSManager::insertSms(SMS sms)
{
    QSqlQuery query;
    query.prepare("INSERT INTO sms (smsid, from, to, date, message) VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, sms.smsid);
    query.bindValue(1, sms.from);
    query.bindValue(2, sms.to);
    query.bindValue(3, sms.date);
    query.bindValue(4, sms.message);
    query.exec();
}

void SMSManager::updateSms(int smsid, SMS sms)
{
    QSqlQuery query;
    query.prepare("UPDATE sms SET smsid = ?, form = ?, to = ?, date = ?, message = ? WHERE smsid = ?");
    query.bindValue(0, sms.smsid);
    query.bindValue(1, sms.from);
    query.bindValue(2, sms.to);
    query.bindValue(3, sms.date);
    query.bindValue(4, sms.message);
    query.bindValue(5, smsid);
    query.exec();
}

void SMSManager::deleteSms(int smsid)
{
    QSqlQuery query;
    query.prepare("DELETE FROM sms WHERE smsid = ?");
    query.bindValue(0, smsid);
    query.exec();
}

QList<SMS> SMSManager::fetchAllSms()
{
    QList<SMS> list;

    QSqlQuery query;
    query.prepare("SELECT * FROM sms WHERE from = ? OR to = ?");
    query.bindValue(0, phonenumber);
    query.bindValue(1, phonenumber);
    query.exec();
    while(query.next()){
        SMS sms;
        sms.smsid = query.value(0).toString();
        sms.from = query.value(1).toString();
        sms.to = query.value(2).toString();
        sms.date = query.value(3).toString();
        sms.message = query.value(4).toString();
        list.push_back(sms);
    }

    return list;
}

SMS SMSManager::fetchSmsById(int smsid)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM sms WHERE smsid = ?");
    query.bindValue(0, smsid);
    query.exec();
    while(query.next()){
        SMS sms;
        sms.smsid = query.value(0).toString();
        sms.from = query.value(1).toString();
        sms.to = query.value(2).toString();
        sms.date = query.value(3).toString();
        sms.message = query.value(4).toString();
        return sms;
    }

    SMS sms;
    return sms;
}
