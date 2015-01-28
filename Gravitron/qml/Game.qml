import QtQuick 2.0
import QtQuick.Controls 1.2

import "menus/functions.js" as Functions

Rectangle {
    property int maxLifepoints: 100
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
        property int lengthFactor: 2
        z: 1000
        objectName: "gameStatus"
        
        id: gameStatus
        width: 100 * lengthFactor
        height: 40
        anchors.topMargin: 5
        anchors.rightMargin: 5
        anchors.top: parent.top;
        anchors.right: parent.right;

        Rectangle {
            width: (parent.lifepoints * parent.lengthFactor)
            height: (parent.height - 2)
            color: "lightgreen"
            anchors.verticalCenter: parent.verticalCenter
            anchors.rightMargin: 1
            anchors.right: parent.right
        }
    }

    Text {
        z: 10
        id: infoBox 
        objectName: "Infobox"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: (parent.height / 2) + 50
        font.pixelSize: 30
        text: qsTr("Waiting for the Server")
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

    Rectangle {
       z: 0
        id: background
        objectName: "background"
       
        width: 100
        height: 100
        Image {
            id: img_background
            height: parent.height
            width: parent.width
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/img/gameBackground"
        }
    }
}
