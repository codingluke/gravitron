#include "headers/GameLoop.h"
#include "headers/Spacecraft.h"
#include "headers/Projectile.h"
#include "headers/InputHandler.h"
#include "headers/Laser.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>
#include <QAbstractEventDispatcher>
#include <cstdlib>

using namespace std;


GameLoop::GameLoop(GameGenerator gGenerator)
{
    gGenerator.generateGame(this);
}

GameLoop::~GameLoop() {
    deleteActors();
    deletePlayer();
    deleteBots();
}

void GameLoop::deleteActors() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++) {
        delete (*it);
    }
}

void GameLoop::deleteBots() {
    vector<Player*>::iterator it;
    for (it = bots.begin(); it < bots.end(); it++) {
        delete (*it);
    }
}

void GameLoop::deletePlayer() {
    vector<Player*>::iterator it;
    for (it = player.begin(); it < player.end(); it++) {
        delete (*it);
    }
}

void GameLoop::setBots(vector<Player*> bots) {
    deleteBots();
    this->bots = bots;
}

void GameLoop::setPlayer(vector<Player*> player) {
    deletePlayer();
    this->player = player;
    this->localPlayer = this->player[0]->spacecraft;
}

void GameLoop::setActors(vector<GameActor*> actors) {
    deleteActors();
    this->actors = actors;
    remapActorsReferences();
}

void GameLoop::remapActorsReferences()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->setActors(&actors);
    }
}

void GameLoop::setRespawTime(int respawnTime) {
    this->respawnTime = respawnTime;
}

void GameLoop::run()
{
    int lag = 0;
    ms_per_update = 35;
    running = true;
    QTime t;
    t.start();
    while (running)
    {
        t.restart();
        processInput();
        update();
        render();
        lag = ms_per_update - t.elapsed();
        if (lag > 0) {
            QThread::msleep(lag);
        }
    }
}

void GameLoop::stop()
{
    running = false;
}

void GameLoop::processInput()
{
    vector<Player*>::iterator it;
    for(it = player.begin(); it != player.end(); it++) {
      (*it)->processInput();
    }
}

void GameLoop::update()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->updateAll();
    }
    for (int i = 0; i < (int) actors.size(); i++)
    {
        Spacecraft* isSpacecraft = NULL;
        isSpacecraft = dynamic_cast<Spacecraft*>(actors[i]);
        if((actors[i]->isKilled()) && (!isSpacecraft)) {
            delete (actors[i]);
            actors.erase(actors.begin() + i);
        }
    }

    actors.shrink_to_fit();
    QThread::msleep(5);
}

void GameLoop::render()
{
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        vector<GameActor*>::iterator it;
        QString serializedViewlist("v");
        for(it = actors.begin(); it != actors.end(); it++) {
            GameActorView *view = (*it)->getView();
            viewlist->push_back(view);
            serializedViewlist += QString::fromStdString(view->toString());
            serializedViewlist += ";";
        }
        serializedViewlist += "\n";
        emit sendViewlist(serializedViewlist);
        emit renderObject(viewlist);
        QThread::msleep(5);
    } else {
        stop();
    }
}
