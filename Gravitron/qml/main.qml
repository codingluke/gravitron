import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Window 2.2
import QtMultimedia 5.0

import "constants.js" as Global
import "functions.js" as Functions
import "menus" as Menus



Window {
    id: win_startWindow
    visible: true
    width: 500
    height: 500
    
    //Image {
        //id: img_backgrond
        //source: "qrc:/img/menuBackgroundImage"
        //height: parent.height
        //width: parent.width
    //}

    Audio {
       id:audioPlayer
       source: "qrc:/audio/menuBackgroundMusic"
       autoLoad: true
       autoPlay: true
       loops: Audio.Infinite
    }

    Menus.Main { id: mainMenu }
    Menus.NewGame { id: newGameMenu }
    Menus.SinglePlayer { id: singlePlayerMenu }
    Menus.Credits { id: creditsMenu }
    Menus.GameSettings { id: gameSettingsMenu }
    Menus.GlobalSettings{ id: globalSettingsMenu }
    Menus.Stats { id: statsMenu }

    ScrollView {
        id: scrollView
        anchors.fill: parent
        height: parent.height
        width: parent.width

        ListView {
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

