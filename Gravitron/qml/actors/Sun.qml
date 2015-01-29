import QtQuick 2.3

Rectangle {
    property int identifier

    id: sun
    color: "#00000000"
    objectName: identifier

    Item {
        id: innerbox
        anchors.centerIn: parent

        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/sun"
        }
    }
}
