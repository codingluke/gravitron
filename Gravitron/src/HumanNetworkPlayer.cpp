#include "headers/HumanNetworkPlayer.h"
#include "headers/GameLoop.h"

HumanNetworkPlayer::HumanNetworkPlayer(Spacecraft* spacecraft,
                                       int frag, TcpServer *server)
                   : HumanPlayer(spacecraft, frag)
{
    NetworkInputHandler *nHandler = new NetworkInputHandler();
    connect(server, SIGNAL(received(QString)),
            nHandler, SLOT(receive(QString)));
}

HumanNetworkPlayer::~HumanNetworkPlayer() {

}
