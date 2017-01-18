#-------------------------------------------------
#
# Project created by QtCreator 2017-01-17T16:24:55
#
#-------------------------------------------------

QT       += core gui network phonon

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_C_Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clienttcp.cpp \
    serveurtcp.cpp \
    pixmapdisplay.cpp \
    graphicview.cpp \
    graphicscene.cpp \
    pixitem.cpp

HEADERS  += mainwindow.h \
    clienttcp.h \
    serveurtcp.h \
    pixmapdisplay.h \
    sleeper.h \
    graphicscene.h \
    graphicview.h \
    pixitem.h

FORMS    += mainwindow.ui

DISTFILES += \
    ZIK/Particle.wav \
    ZIK/TirLaser.wav \
    ZIK/asteroidEnd.wav \
    ZIK/MainTheme1.wav \
    ZIK/MainTheme2.wav \
    ZIK/MainTheme3.wav \
    ZIK/MainTheme4.wav \
    ZIK/MainTheme5.wav \
    ZIK/MainTheme6.wav \
    ZIK/MainTheme7.wav \
    ZIK/MainTheme8.wav \
    ZIK/MainTheme9.wav \
    ZIK/MainTheme10.wav \
    ZIK/MainTheme11.wav \
    PIC/asteroide.png \
    PIC/Asteroid.png \
    PIC/eploded.png \
    PIC/Galaxie1.png \
    PIC/Galaxie2.png \
    PIC/fissure.png \
    PIC/Galaxie3.png \
    PIC/missile.png \
    PIC/Missile1.png \
    PIC/particle1.png \
    PIC/partial.png \
    PIC/particle2.png \
    PIC/test.png \
    PIC/Vaisseau_gasOn1.png \
    PIC/Vaisseau_gasOn2.png \
    PIC/Vaisseau_gasOn3.png \
    PIC/vaisseau_vide.png \
    PIC/Vaisseau1.png \
    PIC/wall.png \
    PIC/wall2.png
