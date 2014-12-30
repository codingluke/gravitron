import QtQuick 2.3

Rectangle {
    property int identifier
    property string scrapImg: "scrap1"

    id: scrap
    width: 55
    height: 55
    color: "#00000000"
    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/" + parent.scrapImg
    }
}
