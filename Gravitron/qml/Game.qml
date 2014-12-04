import QtQuick 2.3
import QtQuick.Controls 1.2

import "functions.js" as Functions

Rectangle {
    id: game_scene
    width: parent.width
    height: parent.height
    color: "black"

    Button {
        id: btn_stop
        text: qsTr("stopGame")
        focus: true
        onClicked: {
            Game.stop();
            Functions.btn_backClicked();
        }
    }
    
}
