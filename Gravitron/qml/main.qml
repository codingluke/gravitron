import QtQuick 2.3
import QtQuick.Window 2.2
import QtMultimedia 5.0


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
    }

    Column {
        id: lvw_mainMenu
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: 10
        spacing: 10


        Button {
            id: btn_newGame
            color: "#000000"
            radius: 0
            label: "New Game"
            focus: true
            KeyNavigation.up: btn_exit
            KeyNavigation.down: btn_settings
            onButtonClick: {
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
            color: "#000000"
            radius: 0
            label: "Settings"
            KeyNavigation.up: btn_newGame
            KeyNavigation.down: btn_credits
            onButtonClick: {
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
            color: "#000000"
            radius: 0
            label: "Credits"
            KeyNavigation.up: btn_settings
            KeyNavigation.down: btn_exit
            onButtonClick: {
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
            color: "#000000"
            radius: 0
            label: "Exit"
            KeyNavigation.up: btn_credits
            KeyNavigation.down: btn_newGame

            onButtonClick: Qt.quit()
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

