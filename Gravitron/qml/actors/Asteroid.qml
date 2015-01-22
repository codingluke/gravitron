import QtQuick 2.3

Rectangle {
    property int identifier
    property real planet
    id: asteroid
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/asteroid"
    }
    transform: Rotation { origin.x: width / 2; origin.y: height / 2 ; angle: asteroid.angle - 90}
}
