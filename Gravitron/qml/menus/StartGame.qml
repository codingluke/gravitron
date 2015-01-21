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
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Lable for the game settings
            text: qsTr("Game Settings")
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the palying field size slider
            text: qsTr("Playing Area Size")
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
            text: qsTr("Number of Enemies")
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
            text: qsTr("Planet Amount")
        }

        Slider {
            id: slide_planetCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.planetCount
            onPressedChanged: Settings.setPlanetCount(slide_planetCount.value)
            minimumValue: 1
            maximumValue: 20
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the amount of astorieds slider
            text: qsTr("Asteroid Amount")
        }

        Slider {
            id: slide_astroidCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
            value: Settings.astroidCount
            onPressedChanged: Settings.setAstroidCount(slide_astroidCount.value)
            minimumValue: 1
            maximumValue: 20
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the frag limit slider
            text: qsTr("Frag Limit")
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
            text: qsTr("Respawn Time")
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
            text: qsTr("Power-Up Settings")
        }

        Button {
            id: btn_startSinglePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a single player game
            text: qsTr("Start")
            //onClicked: MListener.startSinglePlayerGame();
            onClicked: Functions.btn_startGameClicked();
        }
    }
}
