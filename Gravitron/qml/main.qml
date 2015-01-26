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

    Menus.Main { id: mainMenu }
    Menus.NewGame { id: newGameMenu }
    Menus.Credits { id: creditsMenu }
    Menus.StartGame { id: startGameMenu }
    Menus.GlobalSettings{ id: globalSettingsMenu }
    Menus.MultiPlayer{ id: multiPlayerMenu }
    Menus.Server { id: serverMenu }
    Menus.Client { id: clientMenu }

    ScrollView {
        id: scrollView
        anchors.fill: parent
        height: parent.height
        width: parent.width

        ListView {
            anchors.topMargin: 20
            header: Text {
                font.bold: true
                font.pixelSize: 30
                anchors.centerIn: parent
                text: "Gravitron"
                height: 50
            }
            id: main_list
            anchors.fill: parent
            anchors.bottom: parent.bottom
            width: parent.width
            height: parent.height
            spacing: 10
            model: mainMenu
        }
    }

    Loader {
        visible: false
        id: loader
        width: parent.width
        height: parent.height
    }
}

