import QtQuick 2.3

Rectangle {
    property int identifier 
    property real angle

    id: actor
    width: 20
    height: 20
    color: "red"
    Text {
         id: buttonLabel
         anchors.centerIn: parent
         text: parent.identifier
    }
    transform: Rotation { origin.x: this.x; origin.y: this.y ; angle: this.angle }
}
