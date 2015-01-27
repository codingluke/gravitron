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
    
    //Image {
        //id: img_backgrond
        //source: "qrc:/img/menuBackgroundImage"
        //height: parent.height
        //width: parent.width
    //}

    //Audio {
       //id:audioPlayer
       //source: "qrc:/audio/menuBackgroundMusic"
       //autoLoad: true
       //autoPlay: true
       //loops: Audio.Infinite
    //}
    
    VisualItemModel {
        id: theModel
        Column {
            spacing: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.horizontalCenter
            Loader { 
                id: modelLoader
                source: "menus/Main.qml" 
            }
        }
    }

    ScrollView {
        id: scrollView
        anchors.fill: parent

        ListView {
            id: main_list
            model: theModel
            header: Text {
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pixelSize: 30
                text: "Gravitron"
                height: 50
            }
            footer: Item { height: 50 }
            anchors.fill: parent
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            spacing: 10
        }
    }

    Loader {
        visible: false
        id: loader
        width: parent.width
        height: parent.height
    }
}

