#include "headers/GravitronSettings.h"
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <iostream>

GravitronSettings::GravitronSettings(QObject *parent) :
    QObject(parent)
{
    load();
}

QDataStream& operator<< (QDataStream& stream, const GravitronSettings& settings)
{
    stream << settings.mDifficulty;
    stream << settings.mFullScreen;
    stream << settings.mMusicSoundVolume;
    stream << settings.mPlayMusic;
    stream << settings.mPlaySounds;
    stream << settings.mPlayerName;
    stream << settings.mPlayingFieldSize;
    stream << settings.mBotsCount;
    stream << settings.mPlanetCount;
    stream << settings.mAstroidCount;
    stream << settings.mFrag;
    stream << settings.mRespawTime;
    stream << settings.mLanguare;
    stream << settings.mNetwork;
    return stream;
}

QDataStream& operator>> (QDataStream& stream, GravitronSettings& settings)
{
    stream >> settings.mDifficulty;
    stream >> settings.mFullScreen;
    stream >> settings.mMusicSoundVolume;
    stream >> settings.mPlayMusic;
    stream >> settings.mPlaySounds;
    stream >> settings.mPlayerName;
    stream >> settings.mPlayingFieldSize;
    stream >> settings.mBotsCount;
    stream >> settings.mPlanetCount;
    stream >> settings.mAstroidCount;
    stream >> settings.mFrag;
    stream >> settings.mRespawTime;
    stream >> settings.mLanguare;
    stream >> settings.mNetwork;
    return stream;
}

void GravitronSettings::load() {
    QString filename="settings.save";
    QFile file(filename);
    if (file.exists() && file.open(QIODevice::ReadWrite) )
    {
        QDataStream stream(&file);
        stream >> *this;
    } else {
        setDefaultSettings();
    }
    file.close();
}

void GravitronSettings::setDefaultSettings() {
    mDifficulty = 2;
    mFullScreen = false;
    mMusicSoundVolume = 50;
    mPlayMusic = true;
    mPlaySounds = true;
    mPlayerName = "Player1";
    mPlayingFieldSize = 500;
    mBotsCount = 3;
    mPlanetCount = 5;
    mAstroidCount = 5;
    mFrag = 3;
    mRespawTime = 30;
    mLanguare = "en";
    mNetwork = false;
}

void GravitronSettings::save() {
    QString filename="settings.save";
    QFile file(filename);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QDataStream stream(&file);
        stream << *this;
    }
    file.close();
}

int GravitronSettings::difficulty() const {
    return mDifficulty;
}

void GravitronSettings::setDifficulty(const int &source) {
    mDifficulty = source;
    save();
    emit difficultyChanged(source);
}

int GravitronSettings::fullScreen() const {
    return mFullScreen;
}

void GravitronSettings::setFullScreen(const bool& source){
    mFullScreen = source;
    save();
    emit fullScreenChanged(source);
}

int GravitronSettings::musicSoundVolume() const{
    return mMusicSoundVolume;
}

void GravitronSettings::setMusicSoundVolume(const int& source){
    mMusicSoundVolume = source;
    save();
    emit musicSoundVolumeChanged(source);
}

bool GravitronSettings::playMusic() const{
    return mPlayMusic;
}

void GravitronSettings::setPlayMusic(const bool& source){
    mPlayMusic = source;
    save();
    emit playMusicChanged(source);
}

bool GravitronSettings::playSounds() const{
    return mPlaySounds;
}

void GravitronSettings::setPlaySounds(const bool& source){
    mPlaySounds = source;
    save();
    emit playSoundsChanged(source);
}

QString GravitronSettings::playerName() const{
    return mPlayerName;
}

void GravitronSettings::setPlayerName(const QString& source){
    mPlayerName = source;
    save();
    emit playerNameChanged(source);
}

int GravitronSettings::playingFieldSize() const{
    return mPlayingFieldSize;
}

void GravitronSettings::setPlayingFieldSize(const int& source) {
    mPlayingFieldSize = source;
    save();
    emit playingFieldSizeChanged(source);
}

int GravitronSettings::botsCount() const {
    return mBotsCount;
}

void GravitronSettings::setBotsCount(const int& source) {
    mBotsCount = source;
    save();
    emit botsCountChanged(source);
}

int GravitronSettings::planetCount() const {
    return mPlanetCount;
}

void GravitronSettings::setPlanetCount(const int& source) {
    mPlanetCount = source;
    save();
    emit planetCountChanged(source);
}

int GravitronSettings::astroidCount() const {
    return mAstroidCount;
}

void GravitronSettings::setAstroidCount(const int& source) {
    mAstroidCount = source;
    save();
    emit astroidCountChanged(source);
}

int GravitronSettings::frag() const {
    return mFrag;
}

void GravitronSettings::setFrag(const int& source) {
    mFrag = source;
    save();
    emit fragChanged(source);
}

int GravitronSettings::respawTime() const {
    return mRespawTime;
}

void GravitronSettings::setRespawTime(const int& source) {
    mRespawTime = source;
    save();
    emit respawTimeChanged(source);
}

QString GravitronSettings::languare() const {
    return mLanguare;
}

void GravitronSettings::setLanguare(const QString& source) {
    mLanguare = source;
    save();
    emit languareChanged(source);
}

bool GravitronSettings::network() const {
    return mNetwork;
}

void GravitronSettings::setNetwork(const bool& source) {
    mNetwork = source;
    save();
}
