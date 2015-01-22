import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: planet
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/planet"
    }
    transform: Rotation { origin.x: width / 2; origin.y: height / 2 ; angle: planet.angle - 90}
}
