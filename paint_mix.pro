QT += quick
QT += serialport
QT += quickcontrols2
QT += quickwidgets
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    scales.cpp \
    scalessmall.cpp \
    scalesbig.cpp \
    worker00.cpp \
    pagefactorymodel.cpp \
    pagemainmodel.cpp \
    worker01.cpp \
    service.cpp \
    xmlredwrite.cpp \
    pageprofilemodel.cpp \
    pagesidebarmodel.cpp \
    motion.cpp \
    pagecolorconfigmodel.cpp \
    pagecolorconfiggridview.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    scales.h \
    scalessmall.h \
    scalesbig.h \
    worker00.h \
    pagefactorymodel.h \
    motion.h \
    pagemainmodel.h \
    worker01.h \
    service.h \
    xmlredwrite.h \
    pageprofilemodel.h \
    pagesidebarmodel.h \
    pagecolorconfigmodel.h \
    pagecolorconfiggridview.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-DriverGC-Desktop_Qt_5_10_0_clang_64bit-Debug/release/ -lDriverGC.1.0.0
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-DriverGC-Desktop_Qt_5_10_0_clang_64bit-Debug/debug/ -lDriverGC.1.0.0
else:unix: LIBS += -L$$PWD/../build-DriverGC-Desktop_Qt_5_10_0_clang_64bit-Debug/ -lDriverGC.1.0.0

INCLUDEPATH += $$PWD/../DriverGC
DEPENDPATH += $$PWD/../DriverGC

DISTFILES +=
