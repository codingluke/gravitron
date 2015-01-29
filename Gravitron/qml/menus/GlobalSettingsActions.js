function getBtnDifficultyText() {

    //: Text of the difficulty button
    var text = qsTr("Difficulty") + ": ";
    switch(Settings.difficulty) {
        //: difficulty easy
        case 1: text += qsTr("Easy"); break;
        //: difficulty middel
        case 2: text += qsTr("Medium"); break;
        //: difficulty hard
        case 3: text += qsTr("Hard"); break;
    }
    return text;
}

function btn_difficultyClicked() {
    var difficulty = Settings.difficulty;
    difficulty++;
    if (difficulty > 3) {
        difficulty = 1;
    }
    Settings.setDifficulty(difficulty);
}

function getBtnFullScreenText() {
    //: Text of the fullscreen button
    var text = qsTr("Fullscreen") + ": ";
    if(Settings.fullScreen === true) {
        //: fullscreen on
        text += qsTr("on")
        win_startWindow.visibility = "FullScreen"
    } else {
        //: fullscreen off
        text += qsTr("off");
        win_startWindow.visibility = "Windowed"
    }
    return text;
}

function btn_fullScreenClicked() {
    Settings.setFullScreen(!Settings.fullScreen);
}

function getBtnPlayMusicText() {
    //: Text of the music button
    var text = qsTr("Music") + ": ";
    if(Settings.playMusic === true) {
        //: music on
        text += qsTr("on")
    } else {
        //: music off
        text += qsTr("off");
    }
    return text;
}

function btn_playMusicClicked() {
    Settings.setPlayMusic(!Settings.playMusic);
}

function getSlideMusicSoundVolumeVlaue() {
    return Settings.musicSoundVolume
}

function slide_musicSoundVolumeChanged() {
    Settings.setMusicSoundVolume(slide_musicSoundVolume.value);
}

function getBtnPlaySoundsText() {
    //: Text of the sounds button
    var text = qsTr("Sounds") + ": ";
    if(Settings.playSounds === true) {
        //: sound on
        text += qsTr("on")
    } else {
        //: sound off
        text += qsTr("off");
    }
    return text;
}

function btn_playSoundsClicked() {
    Settings.setPlaySounds(!Settings.playSounds);
}

function getTxtPlayerNameText() {
    return Settings.playerName;
}

function txt_playerNameChanged() {
   Settings.setPlayerName(txt_playerName.text)
}


var currentLanguage;
function getLanguage() {
    var language = Settings.language;
    currentLanguage = language;
    var lang = 0;
    if(language == "de") {
        lang = qsTr("langGerman");
    } else if (language == "en") {
        lang = qsTr("langEnglish");
    }
    return lang;
}

function btn_languageClicked() {
   if(currentLanguage == "de") {
        Settings.setLanguage("en");
   } else if (currentLanguage == "en") {
        Settings.setLanguage("de");
   }
   modelLoader.source = "";
   modelLoader.source = "GlobalSettings.qml"
}
