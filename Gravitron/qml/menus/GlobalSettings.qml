import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0

import "constants.js" as Global
import "functions.js" as Functions
import "GlobalSettingsActions.js" as SettingsFunctions
import QtQuick.LocalStorage 2.0

VisualItemModel {
    Column {
        id: col_settingsSubMenu
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
            id: txt_settingsHeadline
            //: Label for the settings menu
            text: qsTr("settings")
        }

        Button {
            id: btn_difficulty
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: SettingsFunctions.getBtnDifficultyText()
            onClicked: SettingsFunctions.btn_difficultyClicked()
        }

        Button {
            id: btn_fullScreen
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: SettingsFunctions.getBtnFullScreenText()
            onClicked: SettingsFunctions.btn_fullScreenClicked()
        }

        Text {
            id: lbl_volume
            height: Global.textHeight
            width: Global.textWidth
            //: Label for the music and sounds volume slider
            text: qsTr("volume")
            font.pixelSize: 12
        }

        Slider {
            id: slide_musicSoundVolume
            width: Global.sliderWidth
            height: Global.sliderHeight
            tickmarksEnabled: false
            stepSize: 1
            activeFocusOnPress: true
            minimumValue: 0
            value: SettingsFunctions.getSlideMusicSoundVolumeVlaue()
            maximumValue: 100
            onPressedChanged: SettingsFunctions.slide_musicSoundVolumeChanged()
        }

        Button {
            id: btn_playMusic
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: SettingsFunctions.getBtnPlayMusicText()
            onClicked: SettingsFunctions.btn_playMusicClicked()
        }

        Button {
            id: btn_playSounds
            width: Global.buttonWidth
            height: Global.buttonHeight
            text: SettingsFunctions.getBtnPlaySoundsText()
            onClicked: SettingsFunctions.btn_playSoundsClicked()
        }

        TextField {
            id: txt_playerName
            height: Global.textFieldHeight
            width: Global.textFieldWidth
            //: Placeholder for the playername input
            placeholderText: qsTr("name")
            text: SettingsFunctions.getTxtPlayerNameText()
            onTextChanged: SettingsFunctions.txt_playerNameChanged()
        }

        Button {
            id: btn_languare
            text: SettingsFunctions.getLanguare()
            width: Global.buttonWidth
            height: Global.buttonHeight
            onClicked: SettingsFunctions.btn_languareClicked()
        }
    }
}
