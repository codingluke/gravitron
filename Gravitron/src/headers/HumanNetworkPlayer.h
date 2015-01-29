#ifndef HUMANNETWORKPLAYER_H
#define HUMANNETWORKPLAYER_H

#include "HumanPlayer.h"
#include "Spacecraft.h"
#include "TcpServer.h"

class HumanNetworkPlayer : public HumanPlayer
{
  public:
      HumanNetworkPlayer(Spacecraft* spacecraft, int frag,
                         TcpServer *server, QString name);

      virtual ~HumanNetworkPlayer();
      void processInput();

  public slots:
      void setNameFromNetwork(QString message);

  protected:
      virtual void execAction(int code);

};

#endif // HUMANNETWORKPLAYER_H
