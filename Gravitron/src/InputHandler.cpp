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

bool InputHandler::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::KeyPress && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      mutex.lock();
      inputs.insert(keyEvent->key());
      mutex.unlock();
  } else if (event->type() == QEvent::KeyRelease && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      mutex.lock();
      inputs.erase(keyEvent->key());
      mutex.unlock();
  }
  return false;
}

