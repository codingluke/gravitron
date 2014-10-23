import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    id: rectangle1
    width: 1280
    height: 780
    transformOrigin: Item.Center

    Image {
        id: img_background
        width: parent.width
        height: parent.height
        source: "../../assets/img/background.jpg"

    }

    Image {
        id: img_logo
        width: 600
        height: 200
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Center
        source: ""
    }



    ListView {
        id: liv_menu
        width: 600
        height: 300
        antialiasing: false
        anchors.top: parent.top
        anchors.topMargin: 200
        anchors.horizontalCenter: parent.horizontalCenter
        transformOrigin: Item.Top
        x: 0
        delegate: Item {
            x: 5
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
        model: ListModel {
            ListElement {
                name: "Neues Spiel"
            }
            ListElement {
                name: "Einstellungen"
            }

            ListElement {
                name: "Credits"
            }

            ListElement {
                name: "Beenden"
            }
        }
    }




}
