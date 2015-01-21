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
            //: Button back to the mainmenu
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: qsTr("Back")
            onClicked: Functions.btn_backClicked()
        }

        Button {
            id: btn_singlePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the single player settings
            text: qsTr("Singleplayer")
            KeyNavigation.up: btn_multiPlayer
            KeyNavigation.down: btn_multiPlayer
            onClicked: Functions.btn_singlePlayerClicked()
        }

        Button {
            id: btn_multiPlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the multi player settings
            text: qsTr("Multiplayer")
            KeyNavigation.up: btn_singlePlayer
            KeyNavigation.down: btn_singlePlayer
            onClicked: Functions.btn_multiPlayerClicked()
        }
    }
}
