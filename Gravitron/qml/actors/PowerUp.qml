import QtQuick 2.3

Rectangle {
    property int identifier
    property real angle
    id: powerUp
    width: 55
    height: 55
    color: "#00000000"
    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        SequentialAnimation on width {
                 loops: Animation.Infinite
                 PropertyAnimation { to: 40 }
                 PropertyAnimation { to: 35 }
             }
        SequentialAnimation on height {
                 loops: Animation.Infinite
                 PropertyAnimation { to: 40 }
                 PropertyAnimation { to: 35 }
             }
        source: "qrc:/img/powerUp"
    }
    transform: Rotation { origin.x: this.x; origin.y: this.y ; angle: 45 }    
}
