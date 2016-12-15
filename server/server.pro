#-------------------------------------------------
#
# Project created by QtCreator 2016-05-25T12:37:17
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = voorbeeldtest1_metServer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    server.cpp \
    menubewerken.cpp

HEADERS  += mainwindow.h \
    server.h \
    menubewerken.h

FORMS    += mainwindow.ui \
    menubewerken.ui
