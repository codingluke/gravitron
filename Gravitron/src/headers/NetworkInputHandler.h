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
        QMutex mutex;
        TcpServer *server; // holds just a reference from outside
        TcpClient *client; // holds just a reverence from outside
        set<int> inputs;
        set<int> remoteinputs;
        bool isServer = false;

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

    public slots:
        void received(QString message);

    private:
        void transferInputs() const;
};

#endif
