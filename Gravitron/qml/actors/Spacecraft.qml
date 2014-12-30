import QtQuick 2.3

Rectangle {
    property int identifier 

    id: spacecraft
    width: 50
    height: 50
    color: "#00000000"
    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: parent.identifier
    }

    Image {
        id: image1
        source: "qrc:/img/spacecraft"
    }


}
