#-------------------------------------------------
#
# Project created by QtCreator 2016-07-21T20:40:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TsunamiEvacModel
TEMPLATE = app


SOURCES += main.cpp\
        tsunamievacmodel.cpp \
    agents.cpp

HEADERS  += tsunamievacmodel.h \
    agents.h \
    matrix/armadillo

FORMS    += tsunamievacmodel.ui
