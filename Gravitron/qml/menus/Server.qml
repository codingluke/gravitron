import QtQuick 2.3
import QtQuick.Controls 1.2

import "constants.js" as Global
import "functions.js" as Functions

Column {
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
        id: lbl_serverPort
        width: Global.textWidth
        //: Label for the music and sounds volume slider
        text: qsTr("Port")
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
        //: Button to start a single player game
        text: qsTr("Create Server")
        onClicked: Functions.btn_createServerClicked();
        style: BtnStyle { text: btn_createServer.text }
    }
    
    Button {
        enabled: false
        id: btn_startMultiplayerGame
        width: Global.buttonWidth
        height: Global.buttonHeight
        text: qsTr("Start")
        onClicked: Functions.btn_startMultiplayerGameClicked();
        style: BtnStyle { text: btn_startMultiplayerGame.text }
    }

    Connections {
        target: TcpServer
        onClientConnected: btn_startMultiplayerGame.enabled = true
    }
}

