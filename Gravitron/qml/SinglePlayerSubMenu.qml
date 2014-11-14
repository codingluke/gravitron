import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

import "constants.js" as Global
import "functions.js" as Functions

Rectangle {
    id: rec_singlePlayerSubMenu
    width: 500
    height: 500
    color: "#bbffffff"


    Column {
        id: col_singlePlayerSubMenu
        spacing: 10
        width: 300
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Button {
            id: btn_backToNewGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Zurück"
            onClicked: Functions.btn_backToNewGameClicked()
        }

        GameSettingsSubMenu {
            height: 500
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
