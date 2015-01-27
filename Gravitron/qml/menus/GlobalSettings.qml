import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0

import "constants.js" as Global
import "functions.js" as Functions
import "GlobalSettingsActions.js" as SettingsFunctions
import QtQuick.LocalStorage 2.0

Column {
    id: col_settingsSubMenu
    spacing: 10
    width: 300

    Button {
        id: btn_back
        width: Global.buttonWidth
        height: Global.buttonHeight
        text: qsTr("Back")
        onClicked: Functions.btn_backClicked()
        style: BtnStyle { text: btn_back.text }
    }

    Text { 
      id: txt_settingsHeadline
      text: qsTr("Settings")
    }
    Button {
        id: btn_difficulty
        width: Global.buttonWidth
        height: Global.buttonHeight
        text: SettingsFunctions.getBtnDifficultyText()
        onClicked: SettingsFunctions.btn_difficultyClicked()
        style: BtnStyle { text: btn_difficulty.text }
    }

    Button {
        id: btn_fullScreen
        width: Global.buttonWidth
        height: Global.buttonHeight
        text: SettingsFunctions.getBtnFullScreenText()
        onClicked: SettingsFunctions.btn_fullScreenClicked()
        style: BtnStyle { text: btn_fullScreen.text }
    }

    Text {
        id: lbl_volume
        text: qsTr("Volume")
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
        style: BtnStyle { text: btn_playMusic.text }
    }

    Button {
        id: btn_playSounds
        width: Global.buttonWidth
        height: Global.buttonHeight
        text: SettingsFunctions.getBtnPlaySoundsText()
        onClicked: SettingsFunctions.btn_playSoundsClicked()
        style: BtnStyle { text: btn_playSounds.text }
    }

    TextField {
        id: txt_playerName
        height: Global.textFieldHeight
        width: Global.textFieldWidth
        placeholderText: qsTr("Name")
        text: SettingsFunctions.getTxtPlayerNameText()
        onEditingFinished: SettingsFunctions.txt_playerNameChanged()
    }

    Button {
        id: btn_language
        text: SettingsFunctions.getLanguare()
        width: Global.buttonWidth
        height: Global.buttonHeight
        onClicked: SettingsFunctions.btn_languageClicked()
        style: BtnStyle { text: btn_language.text }
    }
}
