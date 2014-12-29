import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0
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
            text: qsTr("back")
            onClicked: Functions.btn_backToNewGameClicked()
        }

        Button {
            id: btn_createMultiplayerGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to create a multiplayergame
            text: qsTr("createMultiPlayerGame")
            onClicked: Functions.btn_createMultiplayerGameClicked()
        }

        Button {
            id: btn_joinGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to join a multiplayergame
            text: qsTr("joinMultiPlayerGame")
            onClicked: Functions.btn_joinGameClicked()
        }

        //Button {
            //id: btn_startSinglePlayer
            //width: Global.buttonWidth
            //height: Global.buttonHeight
            ////: Button to start a multiplayergame
            //text: qsTr("startMultiPlayerGame")
        //}
    }
}
