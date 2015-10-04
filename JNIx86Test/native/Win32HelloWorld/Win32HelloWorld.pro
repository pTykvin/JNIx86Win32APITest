TEMPLATE = lib
TARGET = libWindow
CONFIG += console c++11 shared
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += "C:/Program Files (x86)/Java/jdk1.8.0_60/include/win32"
INCLUDEPATH += "C:/Program Files (x86)/Java/jdk1.8.0_60/include"

SOURCES += main.cpp

HEADERS += \
    ../h/Win32HelloWorld.h

