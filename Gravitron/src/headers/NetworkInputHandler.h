#ifndef NETWORK_INPUT_HANDLER_H
#define NETWORK_INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include "TcpServer.h"
#include "TcpClient.h"

using namespace std;

class NetworkInputHandler : public QObject
{
    Q_OBJECT

    private:
      TcpServer *server;
      TcpClient *client;
      set<int> inputs;
      set<int> remoteinputs;
      QMutex mutex;
      bool isServer;

    public:
        NetworkInputHandler();
        NetworkInputHandler(TcpClient *client);
        NetworkInputHandler(TcpServer *server);
        ~NetworkInputHandler();

        set<int> getInputs();
        set<int> getRemoteInputs();
        void removeInputCode(int code);
        void insertInputCode(int code);

    protected:
        bool eventFilter(QObject *obj, QEvent *event);

    private slot:
        void received(QString message);

    private:
        void sendInputs();

};

#endif
