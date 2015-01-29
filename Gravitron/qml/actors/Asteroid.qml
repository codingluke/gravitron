import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: asteroid
    objectName: identifier
    color: "#00000000"

    Item {
        id: innerbox
        width: 64
        height: 55
        anchors.centerIn: parent

        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/asteroid"
            transform: Rotation {
                origin.x: innerbox.width / 2
                origin.y: innerbox.height / 2
                angle: asteroid.angle - 90
            }
        }
    }
}
