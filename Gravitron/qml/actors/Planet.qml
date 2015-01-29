import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: planet
    objectName: identifier
    color: "#00000000"
    width: 67
    height: 49

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/planet"
        transform: Rotation {
            origin.x: planet.width / 2
            origin.y: planet.height / 2
            angle: planet.angle - 90
        }
    }
}
