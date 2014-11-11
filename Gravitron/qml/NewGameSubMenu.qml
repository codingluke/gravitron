import QtQuick 2.0
import QtQuick.Controls 1.2
import Game 1.0

Column {
    width: 100
    height: 160
    spacing: 10
    anchors.verticalCenter: parent.verticalCenter

    Button {
        id: btn_singelPlayer
        text: "Einzel Spieler"
        KeyNavigation.up: btn_multiPlayer
        KeyNavigation.down: btn_multiPlayer
        onClicked: {
            myGame.stop();
        }
    }

    Button {
        id: btn_multiPlayer
        text: "Mehr Spieler"
        KeyNavigation.up: btn_singelPlayer
        KeyNavigation.down: btn_singelPlayer
        onClicked: {
            myGame.start();
        }
    }

    Game {
        id: myGame
    }
}
