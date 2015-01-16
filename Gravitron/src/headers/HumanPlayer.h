#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"
#include "Spacecraft.h"
#include "GameLoop.h"
#include "InputHandler.h"

class HumanPlayer : public Player
{
    Q_OBJECT

    private:
      InputHandler *inputHandler;

    public:
        HumanPlayer(Spacecraft* spacecraft, int frag, GameLoop *loop);
        virtual ~HumanPlayer();

        void processInput();

    private:
        void execAction(int code);

    private slots:
        void setActiveWeapon(int weaponNumber);

};

#endif // HUMANPLAYER_H
