#-------------------------------------------------
#
# Project created by QtCreator 2016-12-03T17:51:17
#
#-------------------------------------------------

QT       += core gui
QT       += core
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    menubewerken.cpp \
    about.cpp \
    bestelserver.cpp

HEADERS  += mainwindow.h \
    menubewerken.h \
    about.h \
    bestelserver.h

FORMS    += mainwindow.ui \
    menubewerken.ui \
    about.ui
