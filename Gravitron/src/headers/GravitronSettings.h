#ifndef GRAVITRONSETTINGS_H
#define GRAVITRONSETTINGS_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QTextStream>

class GravitronSettings : public QObject
{
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

    Q_PROPERTY(bool playMusic
           READ playMusic
           WRITE setPlayMusic
           NOTIFY playMusicChanged)

    Q_PROPERTY(bool playSounds
           READ playSounds
           WRITE setPlaySounds
           NOTIFY playSoundsChanged)

    Q_PROPERTY(QString playerName
           READ playerName
           WRITE setPlayerName
           NOTIFY playerNameChanged)

    Q_PROPERTY(int playingFieldSize
           READ playingFieldSize
           WRITE setPlayingFieldSize
           NOTIFY playingFieldSizeChanged)

    Q_PROPERTY(int botsCount
       READ botsCount
       WRITE setBotsCount
       NOTIFY botsCountChanged)

    Q_PROPERTY(int planetCount
       READ planetCount
       WRITE setPlanetCount
       NOTIFY planetCountChanged)

    Q_PROPERTY(int astroidCount
       READ astroidCount
       WRITE setAstroidCount
       NOTIFY astroidCountChanged)

    Q_PROPERTY(int frag
       READ frag
       WRITE setFrag
       NOTIFY fragChanged)

    Q_PROPERTY(int respawTime
       READ respawTime
       WRITE setRespawTime
       NOTIFY respawTimeChanged)

    Q_PROPERTY(QString language
       READ language
       WRITE setLanguage
       NOTIFY languageChanged)

    Q_PROPERTY(bool network
       READ network
       WRITE setNetwork)

    public:
        explicit GravitronSettings(QObject *parent = 0);

        Q_INVOKABLE int difficulty() const;
        Q_INVOKABLE void setDifficulty(const int& source);
        Q_INVOKABLE int fullScreen() const;
        Q_INVOKABLE void setFullScreen(const bool& source);
        Q_INVOKABLE float musicSoundVolume() const;
        Q_INVOKABLE void setMusicSoundVolume(const float& source);
        Q_INVOKABLE bool playMusic() const;
        Q_INVOKABLE void setPlayMusic(const bool& source);
        Q_INVOKABLE bool playSounds() const;
        Q_INVOKABLE void setPlaySounds(const bool& source);
        Q_INVOKABLE QString playerName() const;
        Q_INVOKABLE void setPlayerName(const QString& source);
        Q_INVOKABLE int playingFieldSize() const;
        Q_INVOKABLE void setPlayingFieldSize(const int& source);
        Q_INVOKABLE int botsCount() const;
        Q_INVOKABLE void setBotsCount(const int& source);
        Q_INVOKABLE int planetCount() const;
        Q_INVOKABLE void setPlanetCount(const int& source);
        Q_INVOKABLE int astroidCount() const;
        Q_INVOKABLE void setAstroidCount(const int& source);
        Q_INVOKABLE int frag() const;
        Q_INVOKABLE void setFrag(const int& source);
        Q_INVOKABLE int respawTime() const;
        Q_INVOKABLE void setRespawTime(const int& source);
        Q_INVOKABLE QString language() const;
        Q_INVOKABLE void setLanguage(const QString& source);
        Q_INVOKABLE bool network() const;
        Q_INVOKABLE void setNetwork(const bool& source);

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
        void playMusicChanged(const bool& source);
        void playSoundsChanged(const bool& source);
        void playerNameChanged(const QString& source);
        void playingFieldSizeChanged(const int& source);
        void botsCountChanged(const int& source);
        void planetCountChanged(const int& source);
        void astroidCountChanged(const int& source);
        void fragChanged(const int& source);
        void respawTimeChanged(const int& source);
        void languageChanged(const QString& source);
        void error(const QString& msg);

    private:
        int mDifficulty;
        bool mFullScreen;
        float mMusicSoundVolume;
        bool mPlayMusic;
        bool mPlaySounds;
        QString mPlayerName;
        int mPlayingFieldSize;
        int mBotsCount;
        int mPlanetCount;
        int mAstroidCount;
        int mFrag;
        int mRespawTime;
        QString mLanguage;
        bool mNetwork;
};


#endif // GRAVITRONSETTINGS_H
