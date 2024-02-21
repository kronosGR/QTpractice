QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    albumlistwidget.cpp \
    albumwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    thumbnailproxymodel.cpp

HEADERS += \
    albumlistwidget.h \
    albumwidget.h \
    mainwindow.h \
    thumbnailproxymodel.h

FORMS += \
    albumlistwidget.ui \
    albumwidget.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SimpleGallery-Core/release/ -lSimpleGallery-Core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SimpleGallery-Core/debug/ -lSimpleGallery-Core
else:unix: LIBS += -L$$OUT_PWD/../SimpleGallery-Core/ -lSimpleGallery-Core

INCLUDEPATH += $$PWD/../SimpleGallery-Core
DEPENDPATH += $$PWD/../SimpleGallery-Core

RESOURCES += \
    resources.qrc
