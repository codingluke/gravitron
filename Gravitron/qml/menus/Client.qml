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
            text: qsTr("Back")
            onClicked: Functions.btn_backToNewGameClicked()
            style: BtnStyle { text: btn_backToNewGame.text }
        }

        Text {
            width: Global.textWidth
            //: Label for the music and sounds volume slider
            text: "Host"
            font.pixelSize: 12
        }

        TextInput {
            id: txt_serverHost
            height: Global.textFieldHeight
            width: Global.textFieldWidth
        }

        Text {
            width: Global.textWidth
            //: Label for the music and sounds volume slider
            text: "Port"
            font.pixelSize: 12
        }

        SpinBox {
            id: txt_clientServerPort
            height: Global.textFieldHeight
            width: Global.textFieldWidth
            minimumValue: 1010
            maximumValue: 9000
        }
        
        Button {
            id: btn_connectToServer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a single player game
            text: "Connect to Server"
            onClicked: Functions.btn_connectToServerClicked();
            style: BtnStyle { text: btn_connectToServer.text }
        }

        Connections {
            target: TcpClient
            onConnected: Functions.btn_joinMultiplayerGameClicked();
        }
    }
}
