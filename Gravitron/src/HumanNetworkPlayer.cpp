#include "headers/HumanNetworkPlayer.h"
#include "headers/GameLoop.h"

HumanNetworkPlayer::HumanNetworkPlayer(Spacecraft* spacecraft, int frag,
                                       TcpServer *server, QString name)
                   : HumanPlayer(spacecraft, frag, name)
{
    inputHandler = new NetworkInputHandler();
    connect(server, SIGNAL(received(QString)),
            inputHandler, SLOT(receive(QString)));
    connect(server, SIGNAL(received(QString)),
            this, SLOT(setNameFromNetwork(QString)));
}


HumanNetworkPlayer::~HumanNetworkPlayer() {

}

void HumanNetworkPlayer::setNameFromNetwork(QString message)
{
    QStringList l = message.split("\n", QString::SkipEmptyParts);
    for (QString s : l) {
        if (s.startsWith("cname")) {
            QString name = s.split(":", QString::SkipEmptyParts)[1];
            setPlayerName(name);
        }
    }
}

void HumanNetworkPlayer::processInput()
{
    if (spacecraft->isKilled()){
        pollRespawn();
    } else {
        set<int> codes = dynamic_cast<NetworkInputHandler*>(inputHandler)->getInputs();
        for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
            if (*it != 0) {
                execAction(*it);
            }
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
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_W);
    } else if (code == Qt::Key_S) {
        spacecraft->shootDown();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        spacecraft->shootLeft();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        spacecraft->shootRight();
        dynamic_cast<NetworkInputHandler*>(inputHandler)->removeInputCode(Qt::Key_D);
    }
}
