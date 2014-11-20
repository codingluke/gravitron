import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Window {
    id: win_startWindow
    visible: true;
    width: 500
    height: 500

    Button {
        id: button1
        text: "New Game"
        focus: true
        onClicked: {
            var component = Qt.createComponent("Game.qml");
            var obj = component.createObject(win_startWindow);
            Game.setQmlParent(obj);
            Game.start();
        }
    }
}
