import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: laser
    objectName: identifier
    color: "#00000000"

    Item {
        id: innerbox
        width: 21
        height: 129
        anchors.centerIn: parent

        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/laser"
            transform: Rotation {
                origin.x: innerbox.width / 2
                origin.y: innerbox.height / 2
                angle: laser.angle - 90
            }
        }
    }
}
