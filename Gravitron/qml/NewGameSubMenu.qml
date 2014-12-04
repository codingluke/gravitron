import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Window 2.0

import "constants.js" as Global
import "functions.js" as Functions

Rectangle {
    id: rec_newGameSubMenu
    width: parent.width
    height: parent.height

    Column {
        id: col_newGameSubMenu
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button bach to the mainmenu
            text: qsTr("back")
            onClicked: Functions.btn_backClicked()
        }

        Button {
            id: btn_singelPlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the singel player settings
            text: qsTr("singelPlayer")
            KeyNavigation.up: btn_multiPlayer
            KeyNavigation.down: btn_multiPlayer
            onClicked: Functions.btn_singelPlayerClicked()
        }

        Button {
            id: btn_multiPlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to the multi player settings
            text: qsTr("multiPlayer")
            KeyNavigation.up: btn_singelPlayer
            KeyNavigation.down: btn_singelPlayer
            onClicked: Functions.btn_multiPlayerClicked()
        }
    }

    Loader {
        width: parent.width
        height: parent.height
        visible: false
        id: load_singlePlayerSubMenu
    }
}
