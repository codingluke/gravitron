#include "headers/NetworkInputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

NetworkInputHandler::NetworkInputHandler()
{
}

NetworkInputHandler::NetworkInputHandler(TcpClient *client)
{
    this->client = client;
}

NetworkInputHandler::NetworkInputHandler(TcpServer *server)
{
    isServer = true;
    this->server = server;
}

NetworkInputHandler::~NetworkInputHandler()
{
}

set<int> NetworkInputHandler::getInputs()
{
    mutex.lock();
    set<int> copy = inputs;
    mutex.unlock();
    return copy;
}

set<int> NetworkInputHandler::getRemoteInputs()
{
    mutex.lock();
    set<int> copy = remoteinputs;
    mutex.unlock();
    return copy;
}

void NetworkInputHandler::insertInputCode(int code)
{
    mutex.lock();
    pair<set<int>::iterator, bool> ret = inputs.insert(code);
    if (ret.second) {
        transferInputs();
    }
    mutex.unlock();
}

void NetworkInputHandler::removeInputCode(int code)
{
    mutex.lock();
    if (inputs.erase(code) == 1) {
        transferInputs();
    }
    mutex.unlock();
}

bool NetworkInputHandler::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::KeyPress && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      insertInputCode(keyEvent->key());
  } else if (event->type() == QEvent::KeyRelease && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      removeInputCode(keyEvent->key());
  }
  return false;
}

void NetworkInputHandler::transferInputs() const
{
    if (isServer) {
        server->transfer("inputs from the server");
    } else {
        client->transfer("inputs from the client");
    }
}

void NetworkInputHandler::received(QString message)
{
    qDebug() << "NetworkInputHandler: received -> " << message;
}

