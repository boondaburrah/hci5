#-------------------------------------------------
#
# Project created by QtCreator 2014-10-08T18:02:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cutepaint
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    doodlearea.cpp

HEADERS  += mainwindow.h \
    doodlearea.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    draw-ellipse.png \
    draw-freehand.png \
    draw-rectangle.png \
    document-save.png \
    .gitignore \
    draw-eraser.png

RESOURCES += \
    resources.qrc
