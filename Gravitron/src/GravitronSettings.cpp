#include "headers/GravitronSettings.h"
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include <iostream>

/**
 * The constructor that is needed by qt.
 * @param parent
 */
GravitronSettings::GravitronSettings(QObject *parent) :
    QObject(parent)
{
    load();
}

/**
 * The overriden << operator for the GravitronSettings class.
 *
 * @param stream The stream to write into.
 * @param settings The settings object to write.
 * @return The written stream.
 */
QDataStream& operator<< (QDataStream& stream, const GravitronSettings& settings)
{
    stream << settings.mDifficulty;
    stream << settings.mFullScreen;
    stream << settings.mMusicSoundVolume;
    stream << settings.mPlayerName;
    stream << settings.mPlayingFieldScaleFactro;
    stream << settings.mNumberOfBots;
    stream << settings.mNumberOfPlanets;
    stream << settings.mNumberOfAstroids;
    stream << settings.mFrag;
    stream << settings.mRespawnTime;
    stream << settings.mLanguage;
    stream << settings.mMultiplayer;
    return stream;
}


/**
 * The overriden >> operator for the GravitronSettings class.
 *
 * @param stream The stream to read.
 * @param settings The settings object.
 * @return The read stream.
 */
QDataStream& operator>> (QDataStream& stream, GravitronSettings& settings)
{
    stream >> settings.mDifficulty;
    stream >> settings.mFullScreen;
    stream >> settings.mMusicSoundVolume;
    stream >> settings.mPlayerName;
    stream >> settings.mPlayingFieldScaleFactro;
    stream >> settings.mNumberOfBots;
    stream >> settings.mNumberOfPlanets;
    stream >> settings.mNumberOfAstroids;
    stream >> settings.mFrag;
    stream >> settings.mRespawnTime;
    stream >> settings.mLanguage;
    stream >> settings.mMultiplayer;
    return stream;
}

/**
 * Load the settings from the save file. If there is no existing save file
 * the default settings will be set.
 */
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

/**
 * Set the default settings.
 */
void GravitronSettings::setDefaultSettings() {
    mDifficulty = 2;
    mFullScreen = false;
    mMusicSoundVolume = 50;
    mPlayerName = "Player1";
    mPlayingFieldScaleFactro = 500;
    mNumberOfBots = 0;
    mNumberOfPlanets = 3;
    mNumberOfAstroids = 10;
    mFrag = 3;
    mRespawnTime = 30;
    mLanguage = "en";
    mMultiplayer = false;
}

/**
 * Store the current settings into the save file. If a savefile already exists
 * it will be overriden.
 */
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

/**
 * Return the difficulty settings.
 * @return The difficulty value.
 */
int GravitronSettings::difficulty() const {
    return mDifficulty;
}

/**
 * Set the difficulty value and save the new settings.
 * @param source The new difficuty.
 */
void GravitronSettings::setDifficulty(const int &source) {
    mDifficulty = source;
    save();
    emit difficultyChanged(source);
}

/**
 * Return the fullscreen switch value.
 * @return The value.
 */
int GravitronSettings::fullScreen() const {
    return mFullScreen;
}

/**
 * Set the switch if the window mode fullscreen or not and save the new settings.
 * @param source The new value.
 */
void GravitronSettings::setFullScreen(const bool& source){
    mFullScreen = source;
    save();
    emit fullScreenChanged(source);
}

/**
 * Return the music volume.
 * @return The volume value.
 */
float GravitronSettings::musicSoundVolume() const{
    return mMusicSoundVolume;
}

/**
 * Set the volume value for the music and sounds and save the new settings.
 * @param source The new volume.
 */
void GravitronSettings::setMusicSoundVolume(const float& source){
    mMusicSoundVolume = source;
    save();
    emit musicSoundVolumeChanged(source);
}

/**
 * Return the player name.
 * @return The player name.
 */
QString GravitronSettings::playerName() const{
    return mPlayerName;
}

/**
 * Set the palyer name and save the new settings.
 * @param source The new player name.
 */
void GravitronSettings::setPlayerName(const QString& source){
    mPlayerName = source;
    save();
    emit playerNameChanged(source);
}

/**
 * Return the playing field scale factor.
 * @return The scale factor.
 */
int GravitronSettings::playingFieldSacleFactor() const{
    return mPlayingFieldScaleFactro;
}

/**
 * Set the playingfield scale factor value and save the new settings.
 * @param source The new factor.
 */
void GravitronSettings::setPlayingFieldScaleFactor(const int& source) {
    mPlayingFieldScaleFactro = source;
    save();
    emit playingFieldScaleFactorChanged(source);
}

/**
 * Return the number of bots.
 * @return The number of bots.
 */
int GravitronSettings::numberOfBots() const {
    return mNumberOfBots;
}

/**
 * Set the number of bots and save the new settings.
 * @param source The new number of bots.
 */
void GravitronSettings::setNumberOfBots(const int& source) {
    mNumberOfBots = source;
    save();
    emit numberOfBotsChanged(source);
}

/**
 * Return the number of planets.
 * @return The number of panets.
 */
int GravitronSettings::numberOfPlanets() const {
    return mNumberOfPlanets;
}

/**
 * Set the number of planets value and save the new settings.
 * @param source The new number of planets.
 */
void GravitronSettings::setNumberOfPlanets(const int& source) {
    mNumberOfPlanets = source;
    save();
    emit numberOfPlanetsChanged(source);
}

/**
 * Return the number of astroids.
 * @return The number of astroids.
 */
int GravitronSettings::numberOfAstroids() const {
    return mNumberOfAstroids;
}

/**
 * Set the number of astroids value and save the new settings.
 * @param source The new number of astroids.
 */
void GravitronSettings::setNumberOfAstroids(const int& source) {
    mNumberOfAstroids = source;
    save();
    emit numberOfAstroidsChanged(source);
}

/**
 * Return the frag.
 * @return The frag.
 */
int GravitronSettings::frag() const {
    return mFrag;
}

/**
 * Set the frag value and save the new settings.
 * @param source The new frag.
 */
void GravitronSettings::setFrag(const int& source) {
    mFrag = source;
    save();
    emit fragChanged(source);
}

/**
 * Return the respawn time.
 * @return The respawn time.
 */
int GravitronSettings::respawnTime() const {
    return mRespawnTime;
}

/**
 * Set the respawn time value and save the new settings.
 * @param source The new respawn time.
 */
void GravitronSettings::setRespawnTime(const int& source) {
    mRespawnTime = source;
    save();
    emit respawnTimeChanged(source);
}

/**
 * Return the language.
 * @return The language.
 */
QString GravitronSettings::language() const {
    return mLanguage;
}

/**
 * Set the language value and save the new settings.
 * @param source The new language.
 */
void GravitronSettings::setLanguage(const QString& source) {
    mLanguage = source;
    save();
    emit languageChanged(source);
}

/**
 * Return the multiplayer switch.
 * @return The value.
 */
bool GravitronSettings::multiplayer() const {
    return mMultiplayer;
}

/**
 * Set the switch if the game is singel- or multiplayer and save the new settings.
 * @param source The new value.
 */
void GravitronSettings::setMultiplayer(const bool& source) {
    mMultiplayer = source;
    save();
}
