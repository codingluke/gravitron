#include "headers/NetworkInputHandler.h"
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <iostream>

using namespace std;

NetworkInputHandler::NetworkInputHandler()
{
}

set<int> NetworkInputHandler::getInputs()
{
    mutex.lock();
    set<int> copy = inputs;
    mutex.unlock();
    return copy;
}

void NetworkInputHandler::setInputsFromString(QString inputsStr)
{
    set<int> tmp;
    QStringList codes = inputsStr.split(",", QString::SkipEmptyParts);
    for (int i = 0; i < codes.size(); ++i) {
        tmp.insert(codes[i].toInt());
    }
    setInputs(tmp);
}

void NetworkInputHandler::setInputs(set<int> newInputs)
{
    mutex.lock();
    inputs = newInputs;
    mutex.unlock();
}

void NetworkInputHandler::removeInputCode(int code)
{
    mutex.lock();
    inputs.erase(code);
    mutex.unlock();
}

void NetworkInputHandler::receive(QString message)
{
    set<int> codes;
    QStringList messages = message.split(";", QString::SkipEmptyParts);
    for (int i = 0; i < messages.size(); ++i) {
        if (messages.at(i).startsWith('i')) {
            setInputsFromString(messages.at(i));
        }
    }
}

