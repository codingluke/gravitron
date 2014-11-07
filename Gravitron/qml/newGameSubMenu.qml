import QtQuick 2.0

Column {
    width: 100
    height: 160
    spacing: 10
    anchors.verticalCenter: parent.verticalCenter

    Button {
        id: btn_singelPlayer
        radius: 0
        color: '#000000'
        label: "Einzel Spieler"
        KeyNavigation.up: btn_multiPlayer
        KeyNavigation.down: btn_multiPlayer
    }

    Button {
        id: btn_multiPlayer
        radius: 0
        color: '#000000'
        label: "Mehr Spieler"
        KeyNavigation.up: btn_singelPlayer
        KeyNavigation.down: btn_singelPlayer
    }
}
