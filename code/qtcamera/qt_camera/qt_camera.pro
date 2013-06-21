#-------------------------------------------------
#
# Project created by QtCreator 2013-06-20T11:23:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_camera
TEMPLATE = app


SOURCES += \
    transmit.cpp \
    qt_camera.cpp \
    main.cpp \
    http_client.cc \
    http/http_message_parser.cc \
    http/third_libs/http_parser.c

HEADERS  += \
    transmit.h \
    qt_camera.h \
    http_client.h \
    http/http_status.h \
    http/http_response.h \
    http/http_request.h \
    http/http_method.h \
    http/http_message_parser.h \
    http/http_message.h \
    http/http_header_items.h \
    http/third_libs/http_parser.h

FORMS    += qt_camera.ui \
    qt_camera.ui

RESOURCES += \
    qt_camera.qrc

INCLUDEPATH += http/
INCLUDEPATH += http/third_libs/
INCLUDEPATH += common/utils/

DEFINES += "__DEBUG"
DEFINES += "__INFO"
DEFINES += "__FATAL"
DEFINES += "__ERROR"
