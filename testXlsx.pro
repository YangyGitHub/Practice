#-------------------------------------------------
#
# Project created by QtCreator 2018-01-24T09:45:33
#
#-------------------------------------------------

QT       += core gui axcontainer
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testXlsx
TEMPLATE = app


include(./QtXlsx/qtxlsx/src/xlsx/qtxlsx.pri)

INCLUDEPATH += $$PWD/include/QtXlsx/


SOURCES += main.cpp\
        Widget.cpp \
    XlsxExcel.cpp \
    TaskImport.cpp

HEADERS  += Widget.h \
    XlsxExcel.h \
    TaskImport.h \
    TaskManangerHeader.h \
    TestManagerHeader.h

FORMS    += Widget.ui
