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
            id: btn_backToNewGame
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button bach to the new game menu
            text: qsTr("back")
            onClicked: Functions.btn_backToNewGameClicked()
        }


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

        Button {
            id: btn_startSinglePlayer
            width: Global.buttonWidth
            height: Global.buttonHeight
            //: Button to start a singel palyer game
            text: qsTr("start")
            //onClicked: MListener.startSinglePlayerGame();
            onClicked: Functions.btn_startGameClicked();
        }
    }
}
