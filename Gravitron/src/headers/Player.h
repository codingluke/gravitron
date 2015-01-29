#ifndef PLAYER_H
#define PLAYER_H

#include "Spacecraft.h"
#include <QObject>
#include <QString>

class Player : public QObject
{
    Q_OBJECT

    protected:
        Spacecraft* spacecraft;
        int frag;
        int roundsToRespawn = 150;
        int respawnCounter;
        QString name = "";

    public:
        Player(QObject *parent = 0);
        Player(Spacecraft* spacecraft, int frag, QString name);
        virtual ~Player();

        virtual void processInput();
        void respawn();

        int getWeapon() const;
        int getHealth() const;
        int getHealthPercentage() const;
        int getRespawnCounter() const;
        int getKillPoints() const;
        int getFrag() const;
        QString getPlayerName() const;
        Spacecraft* getSpacecraft() const;
        void setPlayerName(QString name);
        void setRoundsToRespawn(int roundsToRespawn);
        void pollRespawn();
        bool isWinner() const;
};
#endif // PLAYER_H
