TEMPLATE = app

QT += qml quick #network?

HEADERS += src/headers

SOURCES += src/main.cpp

RESOURCES += assets/img/img.qrc assets/audio/audio.qrc qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
