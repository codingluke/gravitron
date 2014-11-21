import QtQuick 2.0
import QtQuick.Controls 1.2
import QMLFileReader 1.0

import "constants.js" as Global
import "functions.js" as Functions

Rectangle {
    id: rec_creditsSubMenu
    width: parent.width
    height: parent.height
    color: "#bbffffff"

    Column {
        id: col_creditsSubMenu
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: "Zurück"
            onClicked: Functions.btn_backClicked()
        }

        Text {
            id: txt_credits
            textFormat: Text.StyledText
        }

        QMLFileReader {
            id: myFile
            source: ":/text/creditsText"
        }

        Component.onCompleted: {
            txt_credits.text =  myFile.read();
        }
    }
}