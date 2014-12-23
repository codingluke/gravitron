#include "headers/InputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

InputHandler::InputHandler()
{
}

void InputHandler::bindFunction(int code, callback func)
{
    bindings[code] = func;
}

void InputHandler::execute()
{
    set<int>::iterator it;
    for(it = inputs.begin(); it != inputs.end(); it++) {
        qDebug() << *it;
    }
    qDebug() << "-----------------";
}

bool InputHandler::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::KeyPress && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      inputs.insert(keyEvent->key());
  } else if (event->type() == QEvent::KeyRelease && obj) {
      QKeyEvent *keyEvent = (QKeyEvent*)event;
      inputs.erase(keyEvent->key());
  }
  return false;
}
