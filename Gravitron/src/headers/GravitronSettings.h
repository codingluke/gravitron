#ifndef GRAVITRONSETTINGS_H
#define GRAVITRONSETTINGS_H

#include <QObject>
#include <QString>
#include <iostream>
#include <QTextStream>

class GravitronSettings : public QObject
{
    Q_OBJECT

    public:
        Q_PROPERTY(int difficulty
               READ difficulty
               WRITE setDifficulty
               NOTIFY difficultyChanged)

        Q_PROPERTY(bool fullScreen
               READ fullScreen
               WRITE setFullScreen
               NOTIFY fullScreenChanged)

        Q_PROPERTY(int musicSoundVolume
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

        Q_PROPERTY(QString languare
           READ languare
           WRITE setLanguare
           NOTIFY languareChanged)

        Q_PROPERTY(bool network
           READ network
           WRITE setNetwork)

        explicit GravitronSettings(QObject *parent = 0);

    public slots:
        int difficulty() const;
        void setDifficulty(const int& source);
        int fullScreen() const;
        void setFullScreen(const bool& source);
        int musicSoundVolume() const;
        void setMusicSoundVolume(const int& source);
        bool playMusic() const;
        void setPlayMusic(const bool& source);
        bool playSounds() const;
        void setPlaySounds(const bool& source);
        QString playerName() const;
        void setPlayerName(const QString& source);
        int playingFieldSize() const;
        void setPlayingFieldSize(const int& source);
        int botsCount() const;
        void setBotsCount(const int& source);
        int planetCount() const;
        void setPlanetCount(const int& source);
        int astroidCount() const;
        void setAstroidCount(const int& source);
        int frag() const;
        void setFrag(const int& source);
        int respawTime() const;
        void setRespawTime(const int& source);
        QString languare() const;
        void setLanguare(const QString& source);
        bool network() const;
        void setNetwork(const bool& source);

        void save();
        void load();
        friend QDataStream& operator<< (QDataStream& stream, const GravitronSettings& settings);
        friend QDataStream& operator>> (QDataStream& stream, GravitronSettings& settings);

    private:
        void setDefaultSettings();

    signals:
        Q_INVOKABLE void difficultyChanged(const int& source);
        Q_INVOKABLE void fullScreenChanged(const bool& source);
        Q_INVOKABLE void musicSoundVolumeChanged(const int& source);
        Q_INVOKABLE void playMusicChanged(const bool& source);
        Q_INVOKABLE void playSoundsChanged(const bool& source);
        Q_INVOKABLE void playerNameChanged(const QString& source);
        Q_INVOKABLE void playingFieldSizeChanged(const int& source);
        Q_INVOKABLE void botsCountChanged(const int& source);
        Q_INVOKABLE void planetCountChanged(const int& source);
        Q_INVOKABLE void astroidCountChanged(const int& source);
        Q_INVOKABLE void fragChanged(const int& source);
        Q_INVOKABLE void respawTimeChanged(const int& source);
        Q_INVOKABLE void languareChanged(const QString& source);
        Q_INVOKABLE void error(const QString& msg);

    private:
        int mDifficulty;
        bool mFullScreen;
        int mMusicSoundVolume;
        bool mPlayMusic;
        bool mPlaySounds;
        QString mPlayerName;
        int mPlayingFieldSize;
        int mBotsCount;
        int mPlanetCount;
        int mAstroidCount;
        int mFrag;
        int mRespawTime;
        QString mLanguare;
        bool mNetwork;
};


#endif // GRAVITRONSETTINGS_H
