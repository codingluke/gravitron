import QtQuick 2.0
import QtQuick.Controls 1.2

import "functions.js" as Functions

Rectangle {
    id: game_scene
    width: parent.width
    height: parent.height
    color: "black"

    Button {
        z: 1000
        id: btn_stop
        text: qsTr("stopGame")
        focus: true
        onClicked: {
            Game.stop();
            Functions.btn_backClicked();
        }
    }

    Rectangle {
        z: 1000
        id: rec_selectLaser
        objectName: "rec_selectLaser"
        y: 35
        width: 50
        height: 50
        color: focus ? "green" : "#FFFFFF"
        border.width: 5

        Image {
            id: img_selectLaser
            height: parent.height
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/img/selectLaser"
        }
    }



    Rectangle {
        objectName: "rec_selectMissile"
        z: 1000
        id: rec_selectMissile
        x: 0
        y: 80
        width: 50
        height: 50
        color: focus ? "green" : "#FFFFFF"
        border.width: 5
        Image {
            id: img_selectMissile
            height: parent.height
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/img/selectMissile"
        }
    }

    Rectangle {
        z: 1000
        id: rec_selectAimMissile
        objectName: "rec_selectAimMissile"
        y: 125
        width: 50
        height: 50
        color: focus ? "green" : "#FFFFFF"
        border.width: 5
        Image {
            id: img_selectAimMissile
            height: parent.height
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/img/selectAimMissile"
        }
    }


}
