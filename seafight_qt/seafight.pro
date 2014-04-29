SOURCES       = main.cpp \
                field.cpp \
                ship.cpp

HEADERS     = field.h \
                ship.h

Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui

Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui


QT += gui declarative widgets
CONFIG += debug_and_release build_all
