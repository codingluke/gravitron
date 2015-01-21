#ifndef HUMANNETWORKPLAYER_H
#define HUMANNETWORKPLAYER_H

#include "HumanPlayer.h"
#include "Spacecraft.h"
#include "TcpServer.h"

class HumanNetworkPlayer : public HumanPlayer
{
  public:
      HumanNetworkPlayer(Spacecraft* spacecraft, int frag, TcpServer *server);

      virtual ~HumanNetworkPlayer();
      void processInput();

  protected:
      virtual void execAction(int code);

};

#endif // HUMANNETWORKPLAYER_H
