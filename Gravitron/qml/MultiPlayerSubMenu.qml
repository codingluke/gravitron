import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

import "constants.js" as Global
import "functions.js" as Functions

Rectangle {
    id: rec_multiPlayerSubMenu
    width: parent.width
    height: parent.height
    color: "#bbffffff"


    Column {
        id: col_multiPlayerSubMenu
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        width: 300


        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Zurück"
            onClicked: Functions.btn_backToNewGameClicked()
        }

        Button {
            id: btn_createGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Spiel erstellen"
        }

        Button {
            id: btn_joinGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Spiel beitreten"
        }

        MultiplayerJoin {

        }

        GameSettingsSubMenu {
            id: gameSettings
        }

        Button {
            id: btn_startSinglePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: qsTr("Starten")
        }

    }
}
