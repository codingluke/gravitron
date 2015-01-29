import QtQuick 2.3

Rectangle {
    property int identifier
    property string scrapImg: "scrap1"
    property real angle
    objectName: identifier
    id: scrap
    color: "#00000000"
    width: 30
    height: 30

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/" + parent.scrapImg

        transform: Rotation {
            origin.x: scrap.width / 2
            origin.y: scrap.height / 2
            angle: scrap.angle - 90
        }
    }
}
