#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T16:24:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_C_Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clienttcp.cpp

HEADERS  += mainwindow.h \
    clienttcp.h

FORMS    += mainwindow.ui
