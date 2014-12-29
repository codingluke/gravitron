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
}
