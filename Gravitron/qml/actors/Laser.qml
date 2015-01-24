import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: laser
    objectName: identifier
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/laser"
    }
    
    transform: Rotation { 
      origin.x: width / 2; 
      origin.y: height / 2 ; 
      angle: laser.angle - 90
    }
}
