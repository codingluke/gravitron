import QtQuick 2.0
import QtQuick.Controls 1.2
import QtPositioning 5.3
import QtQuick.Layouts 1.0
import GravitronSettings 1.0

Rectangle {
   // width: parent.width
  //  height: parent.height
    width :1024
    height: 256
    color: "#bbffffff"
    Text {
        id: txt_settingsHeadline
        text: "Einstellungen"
        font.pointSize: 15
    }

    /*GroupBox {
        id: group_difficulty
        x: 8
        y: 29
        width: 314
        height: 72
        title: qsTr("Schwäre")

        ExclusiveGroup { id: difficultyGroup }
        RadioButton {
            id: rbtn_difficultyHard
            x: 207
            y: 10
            text: qsTr("Schwer")
            activeFocusOnPress: true
            exclusiveGroup: difficultyGroup
            onClicked: gravitronSettings.setDifficulty(3)
        }

        RadioButton {
            id: rbtn_difficultyMiddel
            x: 108
            y: 10
            text: qsTr("Mittel")
            activeFocusOnPress: true
            exclusiveGroup: difficultyGroup
            onClicked: gravitronSettings.setDifficulty(2)
        }

        RadioButton {
            id: rbtn_difficultyEasy
            x: 0
            y: 10
            text: qsTr("Einfach")
            checked: true
            activeFocusOnPress: true
            exclusiveGroup: difficultyGroup
            onClicked: gravitronSettings.setDifficulty(1)
        }
    }

    GravitronSettings {
        id: gravitronSettings
        onDifficultyChanged: {
            console.log(difficulty);
        }
    } */

    Button {
        id: btn_difficulty
        x: 8
        y: 33
        width: 286
        height: 27
        text: "Schwierigkeit: " + Settings.difficulty
        onClicked: {
            var difficulty = Settings.difficulty;
            difficulty++;
            if (difficulty > 3) {
                difficulty = 1;
            }
            Settings.setDifficulty(difficulty);
        }
    }

    Button {
        id: btn_fullScreen
        x: 8
        y: 66
        width: 286
        height: 27
        text: "Vollbild: " + Settings.fullScreen
        onClicked: {
            Settings.setFullScreen(!Settings.fullScreen);
        }
    }

    Slider {
        id: slide_musicSoundVolume
        x: 8
        y: 114
        width: 286
        height: 28
        tickmarksEnabled: false
        stepSize: 1
        activeFocusOnPress: true
        minimumValue: 0
        value: Settings.musicSoundVolume
        maximumValue: 100
        onValueChanged: {
            Settings.setMusicSoundVolume(slide_musicSoundVolume.value)
        }
    }

    Text {
        id: text1
        x: 16
        y: 99
        width: 270
        height: 22
        text: qsTr("Lautstärke")
        font.pixelSize: 12
    }

    CheckBox {
        id: chk_playMusic
        x: 8
        y: 148
        text: qsTr("Musik")
        checked: Settings.playMusic
        onCheckedChanged: {
            Settings.setPlayMusic(chk_playMusic.checked)
        }
    }

    CheckBox {
        id: chk_playSounds
        x: 172
        y: 148
        text: qsTr("Sounds")
        checked: Settings.playSounds()
        onCheckedChanged: {
            Settings.setPlaySounds(chk_playSounds.checked)
        }
    }

    TextField {
        id: txt_playerName
        x: 9
        y: 176
        width: 285
        height: 25
        placeholderText: qsTr("Name")
        text: Settings.playerName
        onTextChanged: {
            Settings.setPlayerName(txt_playerName.text)
        }
    }



}
