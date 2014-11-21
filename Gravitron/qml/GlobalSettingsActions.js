function getBtnDifficultyText() {
    var text = "Schwierigkeit: ";
    switch(Settings.difficulty) {
        case 1: text += "Leicht"; break;
        case 2: text += "Mittel"; break;
        case 3: text += "Schwer"; break;
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
    var text = "Vollbild: ";
    text += Settings.fullScreen === true ? "an" : "aus";
    return text;
}

function btn_fullScreenClicked() {
    Settings.setFullScreen(!Settings.fullScreen);
}

function getBtnPlayMusicText() {
    var text = "Musik: ";
    text += Settings.playMusic === true ? "an" : "aus";
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
    var text = "Sounds: ";
    text += Settings.playSounds === true ? "an" : "aus";
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
