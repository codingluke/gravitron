import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: missile
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/laser"
    }
    transform: Rotation { origin.x: this.x; origin.y: this.y ; angle: 45 }
}
