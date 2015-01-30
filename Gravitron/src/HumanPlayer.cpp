#include "headers/HumanPlayer.h"
#include "headers/GameLoop.h"
#include <QCoreApplication>

HumanPlayer::HumanPlayer(Spacecraft *spacecraft, int frag, QString name)
  : Player(spacecraft, frag, name)
{
    inputHandler = new InputHandler();
    QCoreApplication::instance()->installEventFilter(inputHandler);
}

HumanPlayer::~HumanPlayer()
{
    QCoreApplication::instance()->removeEventFilter(inputHandler);
    delete inputHandler;
}

void HumanPlayer::processInput()
{
    if (spacecraft->isKilled()){
        pollRespawn();
    } else {
        set<int> codes = dynamic_cast<InputHandler*>(inputHandler)->getInputs();
        for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
            execAction(*it);
        }
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
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_W);
    } else if (code == Qt::Key_S) {
        spacecraft->shootDown();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        spacecraft->shootLeft();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        spacecraft->shootRight();
        dynamic_cast<InputHandler*>(inputHandler)->removeInputCode(Qt::Key_D);
    }
}
