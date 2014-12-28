import QtQuick 2.3

Rectangle {
    property int identifier

    id: planet
    width: 50
    height: 50
    color: "#FF000000"
    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: parent.identifier
    }

    Image {
        id: image1
        width: parent.width
        height: parent.height
        source: "qrc:/img/planet"
    }
}
