import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtMultimedia 5.0

Window {
    id: win_startWindow
    visible: true
    width: 500
    height: 500

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
    }

    Column {
        id: lvw_mainMenu
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
        spacing: 10

        Button {
            id: btn_newGame
            text: "New Game"
            focus: true
            KeyNavigation.up: btn_exit
            KeyNavigation.down: btn_settings
            onClicked: {
                hideAllSubMenus()
                if (newGameSubMenu.visible) {
                    newGameSubMenu.visible = false;
                } else {
                    newGameSubMenu.visible = true
                }
            }
        }

        Button {
            id: btn_settings
            text: "Settings"
            KeyNavigation.up: btn_newGame
            KeyNavigation.down: btn_credits
            onClicked: {
                hideAllSubMenus()
                if (settingsSubMenu.visible) {
                    settingsSubMenu.visible = false;
                } else {
                    settingsSubMenu.visible = true
                }
            }
        }

        Button {
            id: btn_credits
            text: "Credits"
            KeyNavigation.up: btn_settings
            KeyNavigation.down: btn_exit
            onClicked: {
                hideAllSubMenus()
                if (creditsSubMenu.visible) {
                    creditsSubMenu.visible = false;
                } else {
                    creditsSubMenu.visible = true
                }
            }
        }

        Button {
            id: btn_exit
            text: "Exit"
            KeyNavigation.up: btn_credits
            KeyNavigation.down: btn_newGame

            onClicked: Qt.quit()
        }
    }

    Loader {
        width: 1024
        height: 256
        anchors.top: parent.top
        anchors.topMargin: 363
        anchors.left: parent.left
        anchors.leftMargin: 170
        visible: false
        id: newGameSubMenu
        source: "NewGameSubMenu.qml"
    }

    Loader {
        width: 1024
        height: 256
        anchors.top: parent.top
        anchors.topMargin: 363
        anchors.left: parent.left
        anchors.leftMargin: 170
        visible: false
        id: creditsSubMenu
        source: "CreditsSubMenu.qml"
    }

    Loader {
        width: 1024
        height: 256
        anchors.top: parent.top
        anchors.topMargin: 363
        anchors.left: parent.left
        anchors.leftMargin: 170
        visible: false
        id: settingsSubMenu
        source: "SettingsSubMenu.qml"
    }

    function hideAllSubMenus() {
        newGameSubMenu.visible = false;
        settingsSubMenu.visible = false;
        creditsSubMenu.visible = false;
    }
}

