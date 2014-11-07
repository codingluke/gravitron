TEMPLATE = app

QT += qml quick #network?

<<<<<<< HEAD
HEADERS += src/headers \
    src/qmlfilereader.h
=======
DESTDIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
RCC_DIR = ../build

HEADERS += src/headers
>>>>>>> 138e3539115b42111657d6f13c49830f3faa6ddc

SOURCES += src/main.cpp \
    src/qmlfilereader.cpp

RESOURCES += assets/img/img.qrc assets/audio/audio.qrc qml/qml.qrc translations/translations.qrc assets/text/text.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
