import QtQuick 2.0
import QtQuick.Controls 1.2

import "menus/functions.js" as Functions

Rectangle {
    property int maxLifepoints: 20
    id: game_scene
    width: parent.width
    height: parent.height
    color: "black"
    z: 3

    Button {
        z: 1000
        id: btn_stop
        text: qsTr("stopGame")
        focus: true
        onClicked: {
            Functions.btn_backClicked();
            Game.stop();
            scrollView.visible = true;
            loader.visible = false;
        }
    }

    Rectangle {
        property int identity: -1;
        property int lifepoints: 20;

        objectName: "gameStatus"
        
        id: gameStatus
        width: 200
        height: 40
        anchors.topMargin: 5
        anchors.rightMargin: 5
        anchors.top: parent.top;
        anchors.right: parent.right;

        Rectangle {
            width: (parent.width - 2) / (20 / parent.lifepoints)
            height: (parent.height - 2)
            color: "lightgreen"
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 1
            anchors.right: parent.right
        }
    }

    Text {
        id: infoBox 
        objectName: "Infobox"
        anchors.centerIn: parent
        text: "Waiting for the Server"
        font.pixelSize: 30
        color: "#ffffff"
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
