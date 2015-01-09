#ifndef NETWORK_INPUT_HANDLER_H
#define NETWORK_INPUT_HANDLER_H

#include <QObject>
#include <QMutex>
#include <set>
#include "TcpServer.h"
#include "TcpClient.h"
#include <QString>

using namespace std;

class NetworkInputHandler : public QObject
{
    Q_OBJECT

    private:
        QMutex mutex;
        set<int> inputs;

    public:
        NetworkInputHandler();

        set<int> getInputs();
        void removeInputCode(int code);
        void setInputs(set<int> newInputs);
        void setInputsFromString(QString inputStr);

    public slots:
        void receive(QString message);

};

#endif
