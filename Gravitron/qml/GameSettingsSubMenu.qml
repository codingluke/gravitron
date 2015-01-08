import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import "constants.js" as Global

Rectangle {
    property int settingsHeight: col_GameSettings.height
    property int settingsWidth: col_GameSettings.width

    height: settingsHeight
    width: settingsWidth
    Column {
        id:col_GameSettings
        spacing: 10

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Lable for the game settings
            text: qsTr("gameSettings")
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
            stepSize: 1
            maximumValue: 50
            minimumValue: 5
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
            stepSize: 1
            maximumValue: 50
            minimumValue: 5
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
