#-------------------------------------------------
#
# Project created by QtCreator 2013-04-17T15:39:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = memoryForSadPeople
TEMPLATE = app


SOURCES += main.cpp\
        gamewindow.cpp \
    memorylogic.cpp \
    memoryhandler.cpp

HEADERS  += gamewindow.h \
    memorylogic.h \
    memoryhandler.h

FORMS    += gamewindow.ui

RESOURCES += \
    images.qrc
