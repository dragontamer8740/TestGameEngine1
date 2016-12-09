#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T20:38:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tge1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    datamanager.cpp \
    player.cpp \
    gameclass.cpp

HEADERS  += mainwindow.h \
    datamanager.h \
    player.h \
    gameclass.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

