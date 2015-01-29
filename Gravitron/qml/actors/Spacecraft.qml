import QtQuick 2.3

Rectangle {
    property int identifier 
    property real angle
    property int controllingPlayerID
    property bool isVisible: true
    property string name: "Johon doo"

    width: 83
    height: 64 

    id: spacecraft
    color: "#00000000"
    objectName: identifier
    visible: isVisible

    Image {
        id: image1
        anchors.centerIn: parent
        source: "qrc:/img/spacecraft"

        transform: Rotation { 
            origin.x: spacecraft.width / 2
            origin.y: spacecraft.height / 2
            angle: spacecraft.angle - 90
        }
    }
    
    Text {
         id: buttonLabel
         anchors.bottom: parent.top
         anchors.bottomMargin: 10
         anchors.horizontalCenter: parent.horizontalCenter
         text: parent.name
         color: "white"
         font.bold: true
    }

}
