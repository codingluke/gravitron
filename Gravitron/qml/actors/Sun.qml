import QtQuick 2.3

Rectangle {
    property int identifier

    id: sun
    color: "#00000000"

    Image {
        id: image1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/img/sun"
    }


}