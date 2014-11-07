TEMPLATE = app

QT += qml quick #network?

HEADERS += src/qmlfilereader.h src/point.h

DESTDIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
RCC_DIR = ../build

SOURCES += src/main.cpp \
    src/qmlfilereader.cpp \
    src/point.cpp


RESOURCES += assets/img/img.qrc assets/audio/audio.qrc qml/qml.qrc translations/translations.qrc assets/text/text.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
