#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T23:35:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = libHelloQt
TEMPLATE = lib
CONFIG += shared


INCLUDEPATH += "C:\Program Files (x86)\Java\jdk1.8.0_60/include"
INCLUDEPATH += "C:\Program Files (x86)\Java\jdk1.8.0_60/include/win32"

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    ../../out/production/JNIx86Test/ru_tykvin_jni_QTHelloWorld.h

FORMS    += mainwindow.ui
