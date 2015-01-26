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

    ScrollView {
        id: scrollView
        anchors.fill: parent
        //height: parent.height
        //width: parent.width

        ListView {
            id: main_list
            model: mainMenu
            header: Text {
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
                font.pixelSize: 30
                text: "Gravitron"
                height: 50
            }
            footer: Item {
                height: 50
            }
            anchors.fill: parent
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            spacing: 10
        }
    }
    
    Menus.NewGame { id: newGameMenu }
    Menus.Credits { id: creditsMenu }
    Menus.StartGame { id: startGameMenu }
    Menus.GlobalSettings{ id: globalSettingsMenu }
    Menus.MultiPlayer{ id: multiPlayerMenu }
    Menus.Server { id: serverMenu }
    Menus.Client { id: clientMenu }

    Loader {
        visible: false
        id: loader
        width: parent.width
        height: parent.height
    }
}

