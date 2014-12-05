#-------------------------------------------------
#
# Project created by QtCreator 2014-11-24T18:19:11
#
#-------------------------------------------------

QT       += core gui \
         network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fuckingHalma
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    battlefield.cpp \
    remoteai.cpp

HEADERS  += mainwindow.h \
    battlefield.h \
    remoteai.h

FORMS    += mainwindow.ui \
    battlefield.ui
