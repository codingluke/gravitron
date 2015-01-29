import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle

    id: asteroid
    objectName: identifier
    color: "#00000000"
    width: 64
    height: 55
    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/asteroid"

        transform: Rotation {
          origin.x: asteroid.width / 2
          origin.y: asteroid.height / 2
          angle: asteroid.angle - 90
        }
    }
}
