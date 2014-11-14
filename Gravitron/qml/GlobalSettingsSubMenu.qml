import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

import "constants.js" as Global
import "functions.js" as Functions
import "GlobalSettingsActions.js" as SettingsFunctions


Rectangle {
    id: rec_settingsSubMenu
    width: parent.width
    height: parent.height
    color: "#bbffffff"


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
            text: "Zurück"
            onClicked: Functions.btn_backClicked()
        }

        Text {
            id: txt_settingsHeadline
            text: "Einstellungen"
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
            text: qsTr("Lautstärke")
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
            onValueChanged: SettingsFunctions.slide_musicSoundVolumeChanged()
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
            placeholderText: qsTr("Name")
            text: SettingsFunctions.getTxtPlayerNameText()
            onTextChanged: SettingsFunctions.txt_playerNameChanged()
        }
    }
}
