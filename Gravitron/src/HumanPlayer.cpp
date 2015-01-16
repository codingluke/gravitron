#include "headers/HumanPlayer.h"
#include "headers/GameLoop.h"
#include <QDebug>

HumanPlayer::HumanPlayer(Spacecraft *spacecraft, int frag, GameLoop* loop) : Player(spacecraft, frag)
{
    //inputHandler = new InputHandler();
    //QCoreApplication::instance()->installEventFilter(inputHandler);
    this->spacecraft->setWeapon(3);
    connect(loop, SIGNAL(activeWeaponPlayer(int)), this, SLOT(setActiveWeapon(int)));
}

HumanPlayer::~HumanPlayer()
{
    QCoreApplication::instance()->removeEventFilter(inputHandler);
    delete inputHandler;
}

void HumanPlayer::processInput()
{
    set<int> codes = inputHandler->getInputs();
    for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
        execAction(*it);
    }
}

void HumanPlayer::execAction(int code)
{
    if (code == Qt::Key_Left) {
        spacecraft->forceLeft();
    } else if (code == Qt::Key_Up) {
        spacecraft->forceAhead();
    } else if (code == Qt::Key_Right) {
        spacecraft->forceRight();
    } else if (code == Qt::Key_Down) {
        spacecraft->forceBack();
    } else if (code == Qt::Key_W) {
        spacecraft->shootUp();
        inputHandler->removeInputCode(Qt::Key_W);
    } else if (code == Qt::Key_S) {
        spacecraft->shootDown();
        inputHandler->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        spacecraft->shootLeft();
        inputHandler->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        spacecraft->shootRight();
        inputHandler->removeInputCode(Qt::Key_D);
    } else if (code == Qt::Key_1) {
        spacecraft->setWeapon(1);
    } else if (code == Qt::Key_2) {
        spacecraft->setWeapon(2);
    } else if (code == Qt::Key_3) {
        spacecraft->setWeapon(3);
    }
}

void HumanPlayer::setActiveWeapon(int weaponNumber)
{
    this->spacecraft->setWeapon(weaponNumber);
}
