import QtQuick 2.3

Rectangle {
    property int identifier 
    property real angle
    property int controllingPlayerID
    property bool isVisible: true
    property string name: "John doe"

    id: spacecraft
    objectName: identifier
    visible: isVisible

    Item {
        id: innerbox
        width: 83
        height: 64 
        anchors.centerIn: parent

        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/spacecraft"

            transform: Rotation { 
                origin.x: innerbox.width / 2
                origin.y: innerbox.height / 2
                angle: spacecraft.angle - 90
            }
        }
        
        Text {
             id: buttonLabel
             anchors.bottom: parent.top
             anchors.bottomMargin: 10
             anchors.horizontalCenter: parent.horizontalCenter
             text: spacecraft.name
             color: "white"
             font.bold: true
        }
    }

}
