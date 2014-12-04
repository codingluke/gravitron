#include "headers/GravitronSettings.h"
#include <QFile>
#include <QDataStream>
#include <iostream>

GravitronSettings::GravitronSettings(QObject *parent) :
    QObject(parent)
{
    mDifficulty = 1;
}

void GravitronSettings::saveToFile() {
    QFile file("gravitronSettings");
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_3);
    std::cout << this;
    out << this;
}

std::ostream& operator<< (std::ostream& stream, const GravitronSettings& settings)
{
    stream << settings.difficulty() << std::endl;
    stream << settings.fullScreen() << std::endl;
    stream << settings.musicSoundVolume() << std::endl;
    stream << settings.playMusic() << std::endl;
    stream << settings.playSounds() << std::endl;
    stream << settings.playerName().toStdString() << std::endl;
    stream << settings.playingFieldSize() << std::endl;
    stream << settings.botsCount() << std::endl;
    stream << settings.planetCount() << std::endl;
    stream << settings.astroidCount() << std::endl;
    stream << settings.frag() << std::endl;
    stream << settings.respawTime() << std::endl;
    stream << settings.languare().toStdString() << std::endl;
    return stream;
}

void GravitronSettings::loadFromFile() {

}


int GravitronSettings::difficulty() const {
    return mDifficulty;
}

void GravitronSettings::setDifficulty(const int &source) {
    mDifficulty = source;
    this->saveToFile();
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

int GravitronSettings::playingFieldSize() const{
    return mPlayingFieldSize;
}

void GravitronSettings::setPlayingFieldSize(const int& source) {
    mPlayingFieldSize = source;
    playingFieldSizeChanged(source);
}

int GravitronSettings::botsCount() const {
    return mBotsCount;
}

void GravitronSettings::setBotsCount(const int& source) {
    mBotsCount = source;
    botsCountChanged(source);
}

int GravitronSettings::planetCount() const {
    return mPlanetCount;
}

void GravitronSettings::setPlanetCount(const int& source) {
    mPlanetCount = source;
    planetCountChanged(source);
}

int GravitronSettings::astroidCount() const {
    return mAstroidCount;
}

void GravitronSettings::setAstroidCount(const int& source) {
    mAstroidCount = source;
    astroidCountChanged(source);
}

int GravitronSettings::frag() const {
    return mFrag;
}

void GravitronSettings::setFrag(const int& source) {
    mFrag = source;
    fragChanged(source);
}

int GravitronSettings::respawTime() const {
    return mRespawTime;
}

void GravitronSettings::setRespawTime(const int& source) {
    mRespawTime = source;
    respawTimeChanged(source);
}

QString GravitronSettings::languare() const {
    return mLanguare;
}

void GravitronSettings::setLanguare(const QString& source) {
    mLanguare = source;
    emit languareChanged(source);
}
