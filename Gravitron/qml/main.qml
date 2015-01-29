import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtMultimedia 5.0

import "menus" as Menus

Window {
    id: win_startWindow
    visible: true
    width: 1000
    height: 1000
    visibility: (Settings.fullScreen === true) ? "FullScreen" : "Windowed";
    
    Audio {
       id:main_audioPlayer
       source: "file:" + applicationDirPath + "/assets/audio/dambient__8-bit-loop.mp3"
       autoLoad: true
       autoPlay: true
       volume: Settings.musicSoundVolume
       loops: Audio.Infinite
    }

    Rectangle {
      color: "#ccc"
      width: parent.width
      height: 60
      z: 2

      Text {
          anchors.centerIn: parent
          font.bold: true
          font.pixelSize: 30
          color: "#CD3333"
          text: "Gravitron"
      }
    }
    
    VisualItemModel {
        id: theModel
        Column {
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            Loader { 
                id: modelLoader
                source: "menus/Main.qml" 
            }
        }
    }

    ScrollView {
        z: 1
        id: scrollView
        anchors.fill: parent

        ListView {
            id: main_list
            model: theModel
            header: Item { height: 70 }
            footer: Item { height: 50 }
            anchors.fill: parent
        }
    }

    Loader {
        z: 3
        visible: false
        id: loader
        width: parent.width
        height: parent.height
    }
}

