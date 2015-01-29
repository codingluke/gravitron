import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: powerUp
    objectName: identifier
    width: 37
    height: 40
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        SequentialAnimation on width {
                 loops: Animation.Infinite
                 PropertyAnimation { to: 40 }
                 PropertyAnimation { to: 35 }
             }
        SequentialAnimation on height {
                 loops: Animation.Infinite
                 PropertyAnimation { to: 40 }
                 PropertyAnimation { to: 35 }
             }
        source: "qrc:/img/powerUp"
        transform: Rotation {
            origin.x: powerUp.width / 2
            origin.y: powerUp.height / 2
            angle: powerUp.angle - 90
        }
    }
}
