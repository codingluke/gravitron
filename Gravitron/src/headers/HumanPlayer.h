#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Spacecraft.h"
#include "GameLoop.h"
#include "InputHandler.h"

class HumanPlayer : public Player
{
    Q_OBJECT

    protected:
      QObject *inputHandler;

    public:
        HumanPlayer(Spacecraft* spacecraft, int frag);
        virtual ~HumanPlayer();

        virtual void processInput();

    protected:
        virtual void execAction(int code);

    private slots:
        void setActiveWeapon(int weaponNumber);

};

#endif // HUMANPLAYER_H
