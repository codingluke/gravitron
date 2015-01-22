import QtQuick 2.3

Rectangle {
    property int identifier 
    property real angle

    id: spacecraft
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/spacecraft"

    }
    Text {
         id: buttonLabel
         anchors.centerIn: parent
         text: parent.angle
    }
    transform: Rotation { origin.x: width / 2; origin.y: height / 2 ; angle: spacecraft.angle - 90}
}
