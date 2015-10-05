#-------------------------------------------------
#
# Project created by QtCreator 2015-09-25T20:26:02
#
#-------------------------------------------------

QT       += core gui

INCLUDEPATH += "C:/Program Files (x86)/Java/jdk1.8.0_60/include/win32"
INCLUDEPATH += "C:/Program Files (x86)/Java/jdk1.8.0_60/include"

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = View3
TEMPLATE = app


SOURCES += main.cpp\
    qgtile.cpp \
    qgmenu.cpp \
    widget.cpp

HEADERS  += widget.h \
    qgtile.h \
    qgmenu.h \
    ../h/QTViewHelloWorld.h \
    main.h

FORMS    += widget.ui
