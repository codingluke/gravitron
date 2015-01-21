#include "headers/HumanPlayer.h"
#include "headers/GameLoop.h"
#include <QDebug>

HumanPlayer::HumanPlayer(Spacecraft *spacecraft, int frag) : Player(spacecraft, frag)
{
    inputHandler = new InputHandler();
    QCoreApplication::instance()->installEventFilter(inputHandler);
    this->spacecraft->setWeapon(3);
}

HumanPlayer::~HumanPlayer()
{
    QCoreApplication::instance()->removeEventFilter(inputHandler);
    delete inputHandler;
}

void HumanPlayer::processInput()
{
    set<int> codes = dynamic_cast<InputHandler*>(inputHandler)->getInputs();
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
        cerr << "HumanPlayer: shootUp before remove\n";
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_W);
        cerr << "HumanPlayer: shootUp after remove\n";
    } else if (code == Qt::Key_S) {
        spacecraft->shootDown();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        spacecraft->shootLeft();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        spacecraft->shootRight();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_D);
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
