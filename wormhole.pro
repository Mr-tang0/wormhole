QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    hole_horizontal.cpp \
    hole_wertical.cpp \
    main.cpp \
    mydesktop.cpp \
    widget.cpp

HEADERS += \
    hole_horizontal.h \
    hole_wertical.h \
    mydesktop.h \
    widget.h

FORMS += \
    hole_horizontal.ui \
    hole_wertical.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

RC_ICONS = res\icon.ico
