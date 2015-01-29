import QtQuick 2.3

Rectangle {
    property int identifier
    property  real angle
    id: missile
    objectName: identifier
    color: "#00000000"

    Item {
        id: innerbox
        width: 40
        height: 80
        anchors.centerIn: parent

        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/missile"
            transform: Rotation {
                origin.x: missile.width / 2
                origin.y: missile.height / 2
                angle: missile.angle - 90
            }
        }
    }
}
