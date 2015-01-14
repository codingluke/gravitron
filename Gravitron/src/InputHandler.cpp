#include "headers/InputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

InputHandler::InputHandler()
{
}

set<int> InputHandler::getInputs()
{
    mutex.lock();
    set<int> copy = inputs;
    mutex.unlock();
    return copy;
}

void InputHandler::insertInputCode(int code)
{
    mutex.lock();
    pair<set<int>::iterator, bool> ret = inputs.insert(code);
    if (ret.second) {
        emit inputsChanged(inputs);
    }
    mutex.unlock();
}

void InputHandler::removeInputCode(int code)
{
    mutex.lock();
    if (inputs.erase(code) == 1) {
        emit inputsChanged(inputs);
    }
    mutex.unlock();
}

bool InputHandler::eventFilter(QObject *obj, QEvent *event)
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

