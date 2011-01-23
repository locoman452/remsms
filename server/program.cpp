#include "program.h"

Program::Program(Log * logger, QObject *parent) :
    QThread(parent)
{
    this->logger = logger;
    logger->addMessage("Program starting");

    server = new Server(logger, this);
}
