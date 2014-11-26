TEMPLATE = app

CONFIG += debug

QT += qml quick #network?

HEADERS += src/headers/GameActor.h \
    src/headers/Vec3f.h \
    src/headers/QmlFileReader.h \
    src/headers/GravitronSettings.h \
    src/headers/GameLoop.h \
    src/headers/Game.h \
    src/headers/GameActorView.h \
    src/headers/MenuListener.h

DESTDIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
RCC_DIR = ../build

SOURCES += src/main.cpp \
    src/GameActor.cpp \
    src/Vec3f.cpp \
    src/Game.cpp \
    src/GameLoop.cpp \
    src/GravitronSettings.cpp \
    src/QmlFileReader.cpp \
    src/GameActorView.cpp \
    src/MenuListener.cpp

RESOURCES += assets/img/img.qrc \
        assets/audio/audio.qrc \
        assets/text/text.qrc \
        qml/qml.qrc \
        translations.qrc

TRANSLATIONS = gravitron_de.ts \
               gravitron_en.ts

lupdate_only {
    SOURCES = qml/*.qml \
              qml/*.js
}

# Additional import path used to resolve QML modules in Qt Creator's code model
# QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
