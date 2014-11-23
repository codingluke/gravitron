import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtMultimedia 5.0

import "constants.js" as Global
import "functions.js" as Functions



Window {
    id: win_startWindow
    visible: true
    width: Screen.width
    height: Screen.height

    Image {
        id: img_backgrond
        source: "qrc:/img/menuBackgroundImage"
        height: parent.height
        width: parent.width
    }

    Audio {
       id:audioPlayer
       source: "qrc:/audio/menuBackgroundMusic"
       autoLoad: true
       autoPlay: true
       loops: Audio.Infinite
    }

    Column {
        id: col_mainMenu
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 10

        Button {
            id: btn_newGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "New Game"
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
            text: "Settings"
            KeyNavigation.up: btn_newGame
            KeyNavigation.down: btn_credits
            onClicked: Functions.btn_settingsClicked()
        }

        Button {
            id: btn_credits
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Credits"
            KeyNavigation.up: btn_settings
            KeyNavigation.down: btn_stats
            onClicked: Functions.btn_creditsClicked()
        }

        Button {
            id: btn_stats
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Statistik"
            KeyNavigation.up: btn_credits
            KeyNavigation.down: btn_exit
            onClicked: Functions.btn_statsClicked()
        }

        Button {
            id: btn_exit
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Exit"
            KeyNavigation.up: btn_credits
            KeyNavigation.down: btn_newGame
            onClicked: Qt.quit()
        }
    }

    Loader {
        width: Screen.width
        height: Screen.height
        visible: false
        id: load_subMenu
    }
}

