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

    GroupBox {
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
    }

    GroupBox {
        id: group_difficulty1
        x: 8
        y: 107
        width: 314
        height: 62
        ExclusiveGroup {
            id: difficultyGroup1
        }

        SpinBox {
            id: spinBox1
            x: 0
            y: 0
            width: 298
            height: 25
        }
        title: qsTr("Auflösung")
    }

    Slider {
        id: sliderHorizontal1
        x: 101
        y: 193
    }
}
