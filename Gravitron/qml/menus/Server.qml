import QtQuick 2.3
import QtQuick.Controls 1.2

import "constants.js" as Global
import "functions.js" as Functions

VisualItemModel {

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        
        Button {
            id: btn_backToNewGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button bach to the new game menu
            text: qsTr("back")
            onClicked: Functions.btn_backToNewGameClicked()
        }

        Text {
            id: lbl_serverPort
            width: Global.textWidth
            //: Label for the music and sounds volume slider
            text: "Port"
            font.pixelSize: 12
        }

        SpinBox {
            id: txt_serverPort
            height: Global.textFieldHeight
            width: Global.textFieldWidth
            minimumValue: 8000
            maximumValue: 9000
        }
        
        Button {
            id: btn_createServer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a singel palyer game
            text: "Create Server"
            onClicked: Functions.btn_createServerClicked();
        }
        
        Button {
            id: btn_sendMessageFromServer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a singel palyer game
            text: "Send test"
            onClicked: Functions.btn_sendMessageFromServer()
        }

        Button {
            id: btn_startMultiplayerGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: qsTr("start")
            onClicked: Functions.btn_startMultiplayerGameClicked();
        }
    }
}
