#ifndef GRAVITRONSETTINGS_H
#define GRAVITRONSETTINGS_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QTextStream>

/**
 * The class manage the settings for the game. The settings saved persistent for each
 * instance of the programm. It is desigend to set the values via qml gui.
 */
class GravitronSettings : public QObject
{
    /** QT stuff */
    Q_OBJECT

    Q_PROPERTY(int difficulty
           READ difficulty
           WRITE setDifficulty
           NOTIFY difficultyChanged)

    Q_PROPERTY(bool fullScreen
           READ fullScreen
           WRITE setFullScreen
           NOTIFY fullScreenChanged)

    Q_PROPERTY(float musicSoundVolume
           READ musicSoundVolume
           WRITE setMusicSoundVolume
           NOTIFY musicSoundVolumeChanged)

    Q_PROPERTY(QString playerName
           READ playerName
           WRITE setPlayerName
           NOTIFY playerNameChanged)

    Q_PROPERTY(int playingFieldSacleFactor
           READ playingFieldSacleFactor
           WRITE setPlayingFieldScaleFactor
           NOTIFY playingFieldScaleFactorChanged)

    Q_PROPERTY(int numberOfBots
       READ numberOfBots
       WRITE setNumberOfBots
       NOTIFY numberOfBotsChanged)

    Q_PROPERTY(int numberOfPlanets
       READ numberOfPlanets
       WRITE setNumberOfPlanets
       NOTIFY numberOfPlanetsChanged)

    Q_PROPERTY(int numberOfAstroids
       READ numberOfAstroids
       WRITE setNumberOfAstroids
       NOTIFY numberOfAstroidsChanged)

    Q_PROPERTY(int frag
       READ frag
       WRITE setFrag
       NOTIFY fragChanged)

    Q_PROPERTY(int respawnTime
       READ respawnTime
       WRITE setRespawnTime
       NOTIFY respawnTimeChanged)

    Q_PROPERTY(QString language
       READ language
       WRITE setLanguage
       NOTIFY languageChanged)

    Q_PROPERTY(bool multiplayer
       READ multiplayer
       WRITE setMultiplayer)

    public:
        explicit GravitronSettings(QObject *parent = 0);

        Q_INVOKABLE int difficulty() const;
        Q_INVOKABLE void setDifficulty(const int& source);
        Q_INVOKABLE int fullScreen() const;
        Q_INVOKABLE void setFullScreen(const bool& source);
        Q_INVOKABLE float musicSoundVolume() const;
        Q_INVOKABLE void setMusicSoundVolume(const float& source);
        Q_INVOKABLE QString playerName() const;
        Q_INVOKABLE void setPlayerName(const QString& source);
        Q_INVOKABLE int playingFieldSacleFactor() const;
        Q_INVOKABLE void setPlayingFieldScaleFactor(const int& source);
        Q_INVOKABLE int numberOfBots() const;
        Q_INVOKABLE void setNumberOfBots(const int& source);
        Q_INVOKABLE int numberOfPlanets() const;
        Q_INVOKABLE void setNumberOfPlanets(const int& source);
        Q_INVOKABLE int numberOfAstroids() const;
        Q_INVOKABLE void setNumberOfAstroids(const int& source);
        Q_INVOKABLE int frag() const;
        Q_INVOKABLE void setFrag(const int& source);
        Q_INVOKABLE int respawnTime() const;
        Q_INVOKABLE void setRespawnTime(const int& source);
        Q_INVOKABLE QString language() const;
        Q_INVOKABLE void setLanguage(const QString& source);
        Q_INVOKABLE bool multiplayer() const;
        Q_INVOKABLE void setMultiplayer(const bool& source);

        void save();
        void load();
        friend QDataStream& operator<< (QDataStream& stream, const GravitronSettings& settings);
        friend QDataStream& operator>> (QDataStream& stream, GravitronSettings& settings);

    private:
        void setDefaultSettings();

    signals:
        void difficultyChanged(const int& source);
        void fullScreenChanged(const bool& source);
        void musicSoundVolumeChanged(const float& source);
        void playerNameChanged(const QString& source);
        void playingFieldScaleFactorChanged(const int& source);
        void numberOfBotsChanged(const int& source);
        void numberOfPlanetsChanged(const int& source);
        void numberOfAstroidsChanged(const int& source);
        void fragChanged(const int& source);
        void respawnTimeChanged(const int& source);
        void languageChanged(const QString& source);
        void error(const QString& msg);

    private:
        /**
         * The difficulty of the game.
         */
        int mDifficulty;

        /**
         * The switch for fullscreen on or off.
         */
        bool mFullScreen;

        /**
         * The volume of the music and sounds.
         * 0 means off.
         * 1 means 100% volume.
         */
        float mMusicSoundVolume;

        /**
         * The name of the local player.
         */
        QString mPlayerName;

        /**
         * The factor the GameField is scaled with.
         */
        int mPlayingFieldScaleFactro;

        /**
         * The number of bots.
         */
        int mNumberOfBots;

        /**
         * The number of Planet.
         */
        int mNumberOfPlanets;

        /**
         * The number of Astroids.
         */
        int mNumberOfAstroids;

        /**
         * The number of kills thats need to win the game.
         */
        int mFrag;

        /**
         * The time to respawn the palyer.
         */
        int mRespawnTime;

        /**
         * The language.
         */
        QString mLanguage;

        /**
         * Switch for Multiplayer on or off.
         */
        bool mMultiplayer;
};


#endif // GRAVITRONSETTINGS_H
