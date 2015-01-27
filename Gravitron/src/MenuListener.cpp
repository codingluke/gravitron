#include "headers/MenuListener.h"


MenuListener::MenuListener(QObject *parent) : QObject(parent) {

}

MenuListener::MenuListener(GravitronSettings *settings, QObject *parent) :
    QObject(parent)
{
    this->settings = settings;
}

void MenuListener::startSinglePlayerGame()
{

}

