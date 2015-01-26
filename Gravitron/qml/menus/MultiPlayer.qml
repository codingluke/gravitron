import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import QtQml.Models 2.1

import "constants.js" as Global
import "functions.js" as Functions

ObjectModel {
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
            //: Button bach to the new game menu
            text: qsTr("Back")
            onClicked: Functions.btn_backToNewGameClicked()
            style: BtnStyle { text: btn_back.text }
        }

        Button {
            id: btn_createMultiplayerGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to create a multiplayergame
            text: qsTr("Create Game")
            onClicked: Functions.btn_createMultiplayerGameClicked()
            style: BtnStyle { text: btn_createMultiplayerGame.text }
        }

        Button {
            id: btn_joinGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to join a multiplayergame
            text: qsTr("Join Game")
            onClicked: Functions.btn_joinGameClicked()
            style: BtnStyle { text: btn_joinGame.text }
        }
    }
}
