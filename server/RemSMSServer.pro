#-------------------------------------------------
#
# Project created by QtCreator 2010-11-04T15:29:40
#
#-------------------------------------------------

QT       += core
QT       += network
QT       += sql

QT       -= gui

TARGET = RemSMSServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    program.cpp \
    server.cpp \
    connectionthread.cpp \
    smsmanager.cpp

HEADERS += \
    program.h \
    server.h \
    connectionthread.h \
    smsmanager.h
