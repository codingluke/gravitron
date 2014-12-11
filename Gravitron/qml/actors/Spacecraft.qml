import QtQuick 2.3

Rectangle {
    property int identifier 

    id: actor
    width: 50
    height: 50
    color: "red"
    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: parent.identifier
    }

    Image {
        id: image1
        x: 0
        y: 1
        width: parent.width
        height: parent.height
        source: "qrc:/img/spacecraft"
    }


}
