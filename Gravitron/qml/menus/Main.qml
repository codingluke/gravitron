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
            id: btn_newGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the new game menu
            text: qsTr("New Game")
            activeFocusOnPress: false
            enabled: true
            focus: true
            KeyNavigation.up: btn_exit
            KeyNavigation.down: btn_settings
            onClicked: Functions.btn_newGameClicked()
        }

        Button {
            id: btn_settings
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the settings menu
            text: qsTr("Settings")
            KeyNavigation.up: btn_newGame
            KeyNavigation.down: btn_credits
            onClicked: Functions.btn_settingsClicked()
        }

        Button {
            id: btn_credits
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the credits menu
            text: qsTr("Credits")
            KeyNavigation.up: btn_settings
            KeyNavigation.down: btn_exit
            onClicked: Functions.btn_creditsClicked()
        }

        Button {
            id: btn_exit
            width: Global.buttonWidth
            height: Global.buttonHeight
            //Button to exit the game
            text: qsTr("Exit")
            KeyNavigation.up: btn_credits
            KeyNavigation.down: btn_newGame
            onClicked: Qt.quit()
        }
    }
}
