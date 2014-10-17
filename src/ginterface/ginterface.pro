#-------------------------------------------------
#
# Project created by QtCreator 2014-09-24T18:08:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ginterface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../tratamento_imagem/Tratamento_imagem.cc \
    ../correlation/Reconhecimento_imagem.cpp

HEADERS  += mainwindow.h \
    ../tratamento_imagem/Tratamento_imagem.h \
    ../correlation/Reconhecimento_imagem.h

FORMS    += mainwindow.ui

RESOURCES += \
    ../mainwindow.qrc
LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui
QT += qt3support
