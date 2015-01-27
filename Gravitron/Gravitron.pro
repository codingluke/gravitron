TEMPLATE = app

CONFIG += c++11 debug

QT += qml quick network testlib 

CONFIG(debug, debug|release):DEFINES+=TEST #For Linux, Mac, ...
CONFIG(Debug, Debug|Release):DEFINES+=TEST #For Windows

unix:!macx {
    QMAKE_CXXFLAGS_DEBUG += -fsanitize=address \
                        -O1 \
                        -fno-omit-frame-pointer

    QMAKE_LFLAGS_DEBUG += -fsanitize=address
}



HEADERS += src/headers/GameActor.h \
    src/headers/Vec3f.h \
    src/headers/QmlFileReader.h \
    src/headers/GravitronSettings.h \
    src/headers/GameLoop.h \
    src/headers/Game.h \
    src/headers/GameActorView.h \
    src/headers/MenuListener.h \ 
    src/headers/Locater.h \
    src/headers/Physics.h \
    src/headers/Spacecraft.h \
    src/headers/Projectile.h \ 
    src/headers/GameField.h \
    src/headers/InputHandler.h \
    src/headers/NetworkInputHandler.h \
    src/headers/Missile.h \
    src/headers/AimMissile.h \
    src/headers/Laser.h \
    src/headers/Planet.h \
    src/headers/Sun.h \
    src/headers/PowerUp.h \
    src/headers/Asteroid.h \
    src/headers/Scrap.h \
    src/headers/TcpClient.h \
    src/headers/TcpServer.h \
    src/headers/Player.h \
    src/headers/HumanPlayer.h \
    src/headers/HumanNetworkPlayer.h \
    src/headers/KiPlayer.h \
    src/headers/KiNetworkPlayer.h \
    src/headers/GameGenerator.h \
    src/headers/ActorsAdjustments.h \
    src/headers/vec3f_tests.h \
    src/headers/physics_tests.h


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
    src/MenuListener.cpp \
    src/Locator.cpp \
    src/Physics.cpp \
    src/Spacecraft.cpp \
    src/Projectile.cpp \
    src/GameField.cpp \
    src/InputHandler.cpp \
    src/NetworkInputHandler.cpp \
    src/Missile.cpp \
    src/AimMissile.cpp \
    src/Laser.cpp \
    src/Planet.cpp \
    src/Sun.cpp \
    src/PowerUp.cpp \
    src/Asteroid.cpp \
    src/Scrap.cpp \
    src/TcpClient.cpp \
    src/TcpServer.cpp \
    src/Player.cpp \
    src/HumanPlayer.cpp \
    src/HumanNetworkPlayer.cpp \
    src/KiPlayer.cpp \
    src/KiNetworkPlayer.cpp \
    src/GameGenerator.cpp \
    src/vec3f_tests.cpp \
    src/physics_tests.cpp


RESOURCES += assets/img/img.qrc \
        assets/audio/audio.qrc \
        assets/text/text.qrc \
        qml/qml.qrc \
        translations.qrc

TRANSLATIONS = gravitron_de.ts \
               gravitron_en.ts

lupdate_only {
    SOURCES = qml/*.qml \
              qml/menus/*.qml \
              qml/actors/*.qml \
              qml/*.js \
              qml/menus/*.js \
              qml/actors/*.js
}

# Additional import path used to resolve QML modules in Qt Creator's code model
# QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
