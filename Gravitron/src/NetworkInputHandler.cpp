#include "headers/NetworkInputHandler.h"
#include <QStringList>

using namespace std;

/**
 * Default constructor.
 */
NetworkInputHandler::NetworkInputHandler()
{
}

/**
 * Returns a copy of the actual input list.
 *
 * @return copy of the actoal input list.
 */
set<int> NetworkInputHandler::getInputs()
{
    mutex.lock();
    set<int> copy = inputs;
    mutex.unlock();
    return copy;
}

/**
 * Sets inputs by a serialized input list.
 *
 * @param inputsStr serialized codes for the input list.
 */
void NetworkInputHandler::setInputsFromString(QString inputsStr)
{
    set<int> tmp;
    QStringList codes = inputsStr.remove(0,1).split(",", QString::SkipEmptyParts);
    for (int i = 0; i < codes.size(); ++i) {
        if (codes[i].toInt() != 0) {
            tmp.insert(codes[i].toInt());
        }
    }
    setInputs(tmp);
}

/**
 * Sets inputs by a new inputs set.
 *
 * @param newInputs  set of new input codes.
 */
void NetworkInputHandler::setInputs(set<int> newInputs)
{
    mutex.lock();
    inputs = newInputs;
    mutex.unlock();
}

/**
 * Removes a code form the list.
 *
 * @param code code to remove
 */
void NetworkInputHandler::removeInputCode(int code)
{
    mutex.lock();
    inputs.erase(code);
    mutex.unlock();
}

/**
 * Slot to receive messages which should be serialized (commaseperated) codes.
 * Comes from the Network in this application.
 *
 * Example: 12334,12334545,2432\n
 *
 * @param message the serialized code list.
 */
void NetworkInputHandler::receive(QString message)
{
    set<int> codes;
    QStringList messages = message.split("\n", QString::SkipEmptyParts);
    for (int i = 0; i < messages.size(); ++i) {
        if (messages.at(i).startsWith('i')) {
            setInputsFromString(messages.at(i));
        }
    }
}

