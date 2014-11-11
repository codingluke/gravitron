TEMPLATE = app

CONFIG += debug

QT += qml quick #network?

<<<<<<< HEAD
HEADERS += src/headers \
    src/gravitronsettings.h \
    src/qmlfilereader.h \
    src/game_loop.h \
    src/game.h \
    src/GameActor.h \
    src/Vec3f.h
=======
HEADERS += src/qmlfilereader.h src/point.h
>>>>>>> 5f98fd7e01a353fa4497525e2f9606037cbae50d

DESTDIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
RCC_DIR = ../build

SOURCES += src/main.cpp \
    src/qmlfilereader.cpp \
<<<<<<< HEAD
    src/gravitronsettings.cpp \
    src/game_loop.cpp \
    src/game.cpp \
    src/GameActor.cpp \
    src/Vec3f.cpp
=======
    src/point.cpp

>>>>>>> 5f98fd7e01a353fa4497525e2f9606037cbae50d

RESOURCES += assets/img/img.qrc assets/audio/audio.qrc qml/qml.qrc translations/translations.qrc assets/text/text.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
