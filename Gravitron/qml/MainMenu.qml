import QtQuick 2.3

Item {
    width: parent.width
    hight: parent.hight

    Row {
        Button {
            id: button1
            text: "New Game"
            focus: true
            onClicked: {
                var component = Qt.createComponent("Game.qml");
                component.createObject(win_startWindow);
            }
        }
        
        Button {
            id: button2
            text: "Exit"
            focus: false
            onClicked: Qt.quit()
        }

    }


}
