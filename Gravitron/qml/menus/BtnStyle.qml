import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2

import "constants.js" as Global

ButtonStyle {
    id: btnStyle
    property string text: "New Button"

    label: Item {
        anchors.fill: parent
        Text {
            anchors.centerIn: parent
            font.pointSize: 14
            text: btnStyle.text
        }
    }
    background: Rectangle {
        implicitWidth: Global.buttonWidth
        implicitHeight: Global.buttonHeight
        border.width: control.activeFocus ? 2 : 1
        border.color: "#fff"
        radius: 0
        gradient: Gradient {
            GradientStop { 
              position: 0
              color: control.pressed ? "#ccc" : "#eee" 
            }
            GradientStop { 
              position: 1
              color: control.pressed ? "#aaa" : "#ccc" 
            }
        }
    }
}

