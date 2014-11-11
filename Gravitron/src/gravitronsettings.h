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
        explicit GravitronSettings(QObject *parent = 0);

        int difficulty() { return mDifficulty; };
     public slots:
        void setDifficulty(const int& source) {
            mDifficulty = source;
            difficultyChanged(source);
        };

    signals:
        void difficultyChanged(const int& source);
        void error(const QString& msg);

    private:
        int mDifficulty;
};


#endif // GRAVITRONSETTINGS_H
