import QtQuick 2.3

Rectangle {
    property int identifier 

    id: actor
    width: 20
    height: 20
    color: "red"
    Text {
         id: buttonLabel
         anchors.centerIn: parent
         text: parent.identifier
    }
}
