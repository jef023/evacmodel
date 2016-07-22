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
    agents.cpp \
    grid.cpp

HEADERS  += tsunamievacmodel.h \
    agents.h \
    grid.h

FORMS    += tsunamievacmodel.ui

unix:!macx: LIBS += -L$$PWD/matrix/linux_lib/ -larmadillo

INCLUDEPATH += $$PWD/matrix
DEPENDPATH += $$PWD/matrix
