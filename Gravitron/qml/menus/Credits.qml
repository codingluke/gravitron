import QtQuick 2.3
import QtQuick.Controls 1.2
import QMLFileReader 1.0

import "../"
import "constants.js" as Global
import "functions.js" as Functions

VisualItemModel {
    Column {
        id: col_creditsSubMenu
        //anchors.horizontalCenter: main_list.horizontalCenter
        //anchors.verticalCenter: main_list.verticalCenter

        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: The back to the main menu
            text: qsTr("Back")
            onClicked: Functions.btn_backClicked()
            style: BtnStyle { text: btn_back.text }
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
