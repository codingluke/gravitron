import QtQuick 2.3

Rectangle {
    property int identifier
    property string scrapImg: "scrap1"
    property real angle
    objectName: identifier
    id: scrap
    color: "#00000000"

    Item {
        id: innerbox
        width: 30
        height: 30
        anchors.centerIn: parent
        Image {
            id: image1
            anchors.centerIn: parent
            source: "qrc:/img/" + parent.parent.scrapImg

            transform: Rotation {
                origin.x: scrap.width / 2
                origin.y: scrap.height / 2
                angle: scrap.angle - 90
            }
        }
    }
}
