import QtQuick 2.3
import QtQuick.Controls 1.2

import "constants.js" as Global
import "functions.js" as Functions
import "GameSettingsActions.js" as GameSettings

VisualItemModel {

    Column {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        
        Button {
            id: btn_backToNewGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button bach to the new game menu
            text: qsTr("Back")
            onClicked: Functions.btn_backToNewGameClicked()
            style: BtnStyle { text: btn_backToNewGame.text }
        }

        Text { text: qsTr("Playing Area Size") } 
        Slider {
            id: slide_playingFieldSize
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.playingFieldSize
            onPressedChanged: {
                Settings.setPlayingFieldSize(slide_playingFieldSize.value)
            }
        }

        Text { text: qsTr("Number of Enemies") } 
        Slider {
            id: slide_botsCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.botsCount
            onPressedChanged: {
                Settings.setBotsCount(slide_botsCount.value)
            }
        }

        Text { text: qsTr("Planet Amount") } 
        Slider {
            id: slide_planetCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.planetCount
            onPressedChanged: {
                Settings.setPlanetCount(slide_planetCount.value)
            }
            minimumValue: 1
            maximumValue: 20
        }

        Text { text: qsTr("Asteroid Amount") } 
        Slider {
            id: slide_astroidCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.astroidCount
            onPressedChanged: {
                Settings.setAstroidCount(slide_astroidCount.value)
            }
            minimumValue: 1
            maximumValue: 20
        }

        Text { text: qsTr("Frag Limit") }
        Slider {
            id: slide_frag
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.frag
            onPressedChanged: {
                Settings.setFrag(slide_frag.value)
            }
        }

        Text { text: qsTr("Respawn Time") } 
        Slider {
            id: slide_respawTime
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.respawTime
            onPressedChanged: {
                Settings.setRespawTime(slide_respawTime.value)
            }
        }

        Button {
            id: btn_startSinglePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: qsTr("Start")
            onClicked: Functions.btn_startGameClicked();
            style: BtnStyle { text: btn_startSinglePlayer.text }
        }
    }
}
