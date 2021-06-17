TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        director.cpp \
        employee.cpp \
        main.cpp \
        manager.cpp \
        master.cpp \
        receiver.cpp

HEADERS += \
    director.h \
    employee.h \
    manager.h \
    master.h \
    receiver.h
