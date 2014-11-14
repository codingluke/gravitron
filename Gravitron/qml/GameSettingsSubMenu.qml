import QtQuick 2.0
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import "constants.js" as Global

Rectangle {   
    Column {
        spacing: 10

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Spiel Eintellungen")
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Spielfeld Größe")
        }

        Slider {
            id: slide_playingFieldSize
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Gegner Anzahl")
        }

        Slider {
            id: slide_botsCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Palnetendichte")
        }

        Slider {
            id: slide_planetCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Asteroiedendichte")
        }

        Slider {
            id: slide_astroidCount
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Abschusslimit")
        }

        Slider {
            id: slide_frag
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("Respawn Zeit")
        }

        Slider {
            id: slide_respawTime
            width: Global.sliderWidth
            height: Global.sliderHeigt
        }

        Text {
            height: Global.textHeight
            width: Global.textWidth
            text: qsTr("PowerUp Einstellungen")
        }

    }
}
