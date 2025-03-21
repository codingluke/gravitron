import QtQuick 2.0
import QtQuick.Controls 1.2
import QtMultimedia 5.0

import "menus/functions.js" as Functions

Rectangle {
    property int maxLifepoints: 100
    id: game_scene
    width: parent.width
    height: parent.height
    color: "black"
    z: 3



    Audio {
       id:game_audioPlayer
       source: "file:" + applicationDirPath + "/assets/audio/edtijo__happy-8bit-pixel-adenture.wav"
       autoLoad: true
       autoPlay: true
       volume: Settings.musicSoundVolume
       loops: Audio.Infinite
    }


    Button {
        z: 1000
        id: btn_stop
        text: qsTr("stopGame")
        focus: true
        onClicked: {
            Functions.btn_backClicked();
            game_audioPlayer.stop();
            main_audioPlayer.play();
            Game.stop();
            scrollView.visible = true;
            loader.visible = false;

        }
    }
    
    Rectangle {
        property int must: 0
        property int have: 0

        id: fragStatus
        objectName: "fragStatus"
        z: 1000
        width: gameStatus.height
        height: gameStatus.height
        color: "white"
        radius: 25
        anchors.verticalCenter: gameStatus.verticalCenter
        anchors.rightMargin: 5
        anchors.right: gameStatus.left
        
        Text {
            anchors.centerIn: parent
            font.bold: true
            font.pixelSize: 18
            text: fragStatus.have
        }

        Rectangle {
            width: 30
            height: 30
            color: "gray"
            radius: 20
            anchors.right: parent.horizontalCenter
            anchors.rightMargin: 10
            anchors.topMargin: 10
            Text {
                anchors.centerIn: parent
                text: fragStatus.must
                color: "#ffffff"
            }
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
            color: "green"
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
