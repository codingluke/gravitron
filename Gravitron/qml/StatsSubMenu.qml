import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

import "constants.js" as Global
import "functions.js" as Functions

Rectangle {
    id: rec_statsSubMenu
    width: parent.width
    height: parent.height


    Column {
        id: col_statsSubMenu
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        width: 300


        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button bach to the mainmenu
            text: qsTr("back")
            onClicked: Functions.btn_backClicked()
        }

        Text {
            id: txt_statsHeadline
            //: Label for the stats
            text: qsTr("stats")
        }
    }
}
