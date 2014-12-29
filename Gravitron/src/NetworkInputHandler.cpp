#include "headers/NetworkInputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

InputHandler::InputHandler()
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
    ret = inputs.insert(code);
    if (ret.second) {
      // sync new input over network
    }
    mutex.unlock();
}

void NetworkInputHandler::removeInputCode(int code)
{
    mutex.lock();
    if (inputs.erase(code) == 1) {
      // sync new input over network
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

