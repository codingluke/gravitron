#ifndef PLAYER_H
#define PLAYER_H

#include "Spacecraft.h"
#include <QObject>

class Player : public QObject
{
    Q_OBJECT

    public:
        Player(QObject *parent = 0);
        Player(Spacecraft* spacecraft, int frag);
        virtual ~Player();

        virtual void processInput();
        void respawn();

    public:
        Spacecraft* spacecraft;
        int frag;

        int getWeapon() const;


};
#endif // PLAYER_H
