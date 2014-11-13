#ifndef GRAVITRONSETTINGS_H
#define GRAVITRONSETTINGS_H

#include <QObject>
#include <QString>

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

    signals:
        void difficultyChanged(const int& source);
        void fullScreenChanged(const bool& source);
        void musicSoundVolumeChanged(const int& source);
        void playMusicChanged(const bool& source);
        void playSoundsChanged(const bool& source);
        void playerNameChanged(const QString& source);

        void error(const QString& msg);

    private:
        int mDifficulty;
        bool mFullScreen;
        int mMusicSoundVolume;
        bool mPlayMusic;
        bool mPlaySounds;
        QString mPlayerName;
};


#endif // GRAVITRONSETTINGS_H
