#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QFile>
#include <QTextStream>

class Log
{
public:
    Log(bool verbose = false, QString filename = "");
    ~Log();

    void addMessage(QString message, int severity = VERBOSE);
    enum { VERBOSE, WARNING, ERROR };

private:
    bool verbose;
    QString filename;

    QFile * filePointer;
    QTextStream * fileStream;
};

#endif // LOG_H
