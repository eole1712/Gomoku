#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T16:27:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gomoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    modifiableQLabel.cpp \
    winchanger.cpp

HEADERS  += mainwindow.h \
    modifiableQLabel.hpp \
    winchanger.hpp

FORMS    += mainwindow.ui
