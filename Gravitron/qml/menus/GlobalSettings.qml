import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

import "../constants.js" as Global
import "../functions.js" as Functions
import "../GlobalSettingsActions.js" as SettingsFunctions
import QtQuick.LocalStorage 2.0

VisualItemModel {
    Column {
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Lable for the game settings
            text: qsTr("gameSettings")
        }
        
        Button {
            id: btn_back
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: The back to the main menu
            text: qsTr("back")
            onClicked: Functions.btn_backClicked()
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the palying field size slider
            text: qsTr("playingFieldSize")
        }

        Slider {
            id: slide_playingFieldSize
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the number of enemies slider
            text: qsTr("numberEnemies")
        }

        Slider {
            id: slide_botsCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the amount of planets slider
            text: qsTr("planetAmount")
        }

        Slider {
            id: slide_planetCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the amount of astorieds slider
            text: qsTr("astroidAmount")
        }

        Slider {
            id: slide_astroidCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the frag limit slider
            text: qsTr("fragLimit")
        }

        Slider {
            id: slide_frag
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the respawn time slider
            text: qsTr("rRespawnTime")
        }

        Slider {
            id: slide_respawTime
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //:Label for the PowerUp settings
            text: qsTr("powerUpSettings")
        }

    }
}
