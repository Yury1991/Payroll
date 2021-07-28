QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    director.cpp \
    directorwindow.cpp \
    employee.cpp \
    employeewindow.cpp \
    errorwindow.cpp \
    fileprogress.cpp \
    logmessage.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    managerwindow.cpp \
    master.cpp \
    masterwindow.cpp \
    optionswindow.cpp \
    receiver.cpp \
    receiverwindow.cpp \
    simpledialogwindow.cpp \
    staffwindow.cpp

HEADERS += \
    director.h \
    directorwindow.h \
    employee.h \
    employeewindow.h \
    errorwindow.h \
    fileprogress.h \
    logmessage.h \
    mainwindow.h \
    manager.h \
    managerwindow.h \
    master.h \
    masterwindow.h \
    optionswindow.h \
    receiver.h \
    receiverwindow.h \
    simpledialogwindow.h \
    staffwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RESOURCES +=

