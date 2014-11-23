function getBtnDifficultyText() {

    //: Text of the difficulty button
    var text = qsTr("difficulty") + ": ";
    switch(Settings.difficulty) {
        //: difficulty easy
        case 1: text += qsTr("easy"); break;
        //: difficulty middel
        case 2: text += qsTr("middel"); break;
        //: difficulty hard
        case 3: text += qsTr("hard"); break;
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
    var text = qsTr("fullscreen") + ": ";
    if(Settings.fullScreen === true) {
        //: fullscreen on
        text += qsTr("on")
    } else {
        //: fullscreen off
        text += qsTr("off");
    }
    return text;
}

function btn_fullScreenClicked() {
    Settings.setFullScreen(!Settings.fullScreen);
}

function getBtnPlayMusicText() {
    //: Text of the music button
    var text = qsTr("music") + ": ";
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
    var text = qsTr("sounds") + ": ";
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
