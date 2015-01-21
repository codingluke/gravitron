#include "headers/HumanNetworkPlayer.h"
#include "headers/GameLoop.h"

HumanNetworkPlayer::HumanNetworkPlayer(Spacecraft* spacecraft,
                                       int frag, TcpServer *server)
                   : HumanPlayer(spacecraft, frag)
{
    inputHandler = new NetworkInputHandler();
    connect(server, SIGNAL(received(QString)),
            inputHandler, SLOT(receive(QString)));
}

HumanNetworkPlayer::~HumanNetworkPlayer() {

}

void HumanNetworkPlayer::processInput()
{
    set<int> codes = dynamic_cast<NetworkInputHandler*>(inputHandler)->getInputs();
    for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
        if (*it != 0) {
            execAction(*it);
        }
    }
}


void HumanNetworkPlayer::execAction(int code)
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
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_W);
        cerr << "HumanPlayer: shootUp after remove\n";
    } else if (code == Qt::Key_S) {
        spacecraft->shootDown();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        spacecraft->shootLeft();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        spacecraft->shootRight();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_D);
    } else if (code == Qt::Key_1) {
        spacecraft->setWeapon(1);
    } else if (code == Qt::Key_2) {
        spacecraft->setWeapon(2);
    } else if (code == Qt::Key_3) {
        spacecraft->setWeapon(3);
    }
}
