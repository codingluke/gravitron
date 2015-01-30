#include "headers/InputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

using namespace std;

/**
 * Default constructor.
 */
InputHandler::InputHandler()
{
}

/**
 * Returns a copy of the actual inputs list.
 * The inputs are saved though a mutex.
 *
 * @return copy of the actual inputs lists.
 */
set<int> InputHandler::getInputs()
{
    mutex.lock();
    set<int> copy = inputs;
    mutex.unlock();
    return copy;
}

/**
 * Inserts a new code into the list.
 * The insertion is threadsave by a mutex.
 *
 * @param code  Code to insert.
 */
void InputHandler::insertInputCode(int code)
{
    mutex.lock();
    pair<set<int>::iterator, bool> ret = inputs.insert(code);
    if (ret.second) {
        emit inputsChanged(inputs);
    }
    mutex.unlock();
}

/**
 * Removes a code form the list.
 * The mutation of the list is threadsave by a mutex.
 *
 * @param code to remove.
 */
void InputHandler::removeInputCode(int code)
{
    mutex.lock();
    if (inputs.erase(code) == 1) {
        emit inputsChanged(inputs);
    }
    mutex.unlock();
}

/**
 * The Event Filter for the QCoreApplication. Filters out just
 * the keyUp and KeyDown events.
 *
 * @param obj   QObject which the event has fired.
 * @param event The QEvent which as been fired.
 *
 * @return always false.
 */
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

