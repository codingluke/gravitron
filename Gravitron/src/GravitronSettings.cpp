#include "headers/GravitronSettings.h"

GravitronSettings::GravitronSettings(QObject *parent) :
    QObject(parent)
{
    mDifficulty = 1;
}

int GravitronSettings::difficulty() const {
    return mDifficulty;
}

void GravitronSettings::setDifficulty(const int &source) {
    mDifficulty = source;
    difficultyChanged(source);
}

int GravitronSettings::fullScreen() const {
    return mFullScreen;
}

void GravitronSettings::setFullScreen(const bool& source){
    mFullScreen = source;
    fullScreenChanged(source);
}

int GravitronSettings::musicSoundVolume() const{
    return mMusicSoundVolume;
}

void GravitronSettings::setMusicSoundVolume(const int& source){
    mMusicSoundVolume = source;
    musicSoundVolumeChanged(source);
}

bool GravitronSettings::playMusic() const{
    return mPlayMusic;
}

void GravitronSettings::setPlayMusic(const bool& source){
    mPlayMusic = source;
    playMusicChanged(source);
}

bool GravitronSettings::playSounds() const{
    return mPlaySounds;
}

void GravitronSettings::setPlaySounds(const bool& source){
    mPlaySounds = source;
    playSoundsChanged(source);
}

QString GravitronSettings::playerName() const{
    return mPlayerName;
}

void GravitronSettings::setPlayerName(const QString& source){
    mPlayerName = source;
    playerNameChanged(source);
}
