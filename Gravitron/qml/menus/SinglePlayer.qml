import QtQuick 2.3
import QtQuick.Controls 1.2

import "../constants.js" as Global
import "../functions.js" as Functions

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

        //GameSettingsSubMenu {
            //id: gameSettings
        //}

        Button {
            id: btn_startSinglePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a singel palyer game
            text: qsTr("start")
            //onClicked: MListener.startSinglePlayerGame();
            onClicked: Functions.btn_startGameClicked();
        }
    }
}
