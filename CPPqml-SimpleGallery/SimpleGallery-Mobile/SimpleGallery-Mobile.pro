TEMPLATE = app

QT += quick qml sql svg

SOURCES += \
        main.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SimpleGallery-Core/release/ -lSimpleGallery-Core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SimpleGallery-Core/debug/ -lSimpleGallery-Core
else:unix: LIBS += -L$$OUT_PWD/../SimpleGallery-Core/ -lSimpleGallery-Core

INCLUDEPATH += $$PWD/../SimpleGallery-Core
DEPENDPATH += $$PWD/../SimpleGallery-Core

contains(ANDROID_TARGET_ARCH,x86) {
ANDROID_EXTRA_LIBS = \
$$[QT_INSTALL_LIBS]/libQt5Sql.so
}
