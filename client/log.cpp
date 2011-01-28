#include "log.h"

#include <QFile>
#include <QIODevice>
#include <QDateTime>
#include <QChar>

#include <iostream>

Log::Log(bool verbose, QString filename){
    this->verbose = verbose;
    this->filename = filename;

    if(filename != ""){
        filePointer = new QFile(filename);

        if(!filePointer->open( QIODevice::WriteOnly | QIODevice::Append ) ){
            this->filename = "";
        }else{
            fileStream = new QTextStream(filePointer);
        }
    }
}

Log::~Log(){
    filePointer->close();
}

void Log::addMessage(QString message, int severity){
    QString timestamp = QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm:ss");
    QString severitytext;

    switch(severity){
    case Log::WARNING:
        severitytext = "WARNING";
        break;

    case Log::ERROR:
        severitytext = "ERROR  ";
        break;

    default:
    case Log::VERBOSE:
        severitytext = "VERBOSE";
        break;
    }

    QString outputMessage = timestamp + " | " + severitytext + " | " + message;

    if(verbose){
        std::cout << outputMessage.toStdString() << std::endl;
    }

    if(filename != ""){
        *fileStream << outputMessage << "\r\n";
        fileStream->flush();
    }
}
