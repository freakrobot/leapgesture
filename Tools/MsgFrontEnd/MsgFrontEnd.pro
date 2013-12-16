#-------------------------------------------------
#
# Project created by QtCreator 2013-12-12T22:37:32
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MsgFrontEnd
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gestureconsumer.cpp

HEADERS  += mainwindow.h \
    gestureconsumer.h

FORMS    += mainwindow.ui
