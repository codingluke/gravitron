import QtQuick 2.3
import QtQuick.Controls 1.2

Rectangle {
    id: game_scene
    width: parent.width
    height: parent.height
    color: "black"

    Button {
        id: btn_stop
        text: "Stop Game"
        focus: true
        onClicked: {
            Game.stop();
            game_scene.destroy();
        }
    }
}
