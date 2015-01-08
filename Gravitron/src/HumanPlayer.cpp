#include "headers/HumanPlayer.h"
#include "headers/GameLoop.h"
#include <QDebug>

HumanPlayer::HumanPlayer(Spacecraft *spacecraft, int frag, GameLoop* loop) : Player(spacecraft, frag)
{
    this->spacecraft->setWappon(3);
    connect(loop, SIGNAL(activeWapponPlayer(int)), this, SLOT(setActiveWappon(int)));
}

HumanPlayer::~HumanPlayer() {

}

void HumanPlayer::setActiveWappon(int wapponNumber) {
    this->spacecraft->setWappon(wapponNumber);
}
