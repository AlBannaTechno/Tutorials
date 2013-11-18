# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW-Windows
TARGET = 04-Datetime
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += comparedates.cpp curdatetime.cpp customdateformats.cpp customtimeformats.cpp dateformats.cpp datetime.cpp daystofrom.cpp init.cpp isvalid.cpp leapyear.cpp main.cpp nofdays.cpp timeformats.cpp unixepoch.cpp utclocal.cpp weekday.cpp
HEADERS += datetime.h
FORMS +=
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
