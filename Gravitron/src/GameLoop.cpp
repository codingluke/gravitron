#include "headers/GameLoop.h"
#include "headers/Spacecraft.h"
#include "headers/Projectile.h"
#include "headers/InputHandler.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>
#include <QAbstractEventDispatcher>
#include <cstdlib>

using namespace std;


GameLoop::GameLoop(InputHandler *inputHandler, GameGenerator *gGenerator)
{
    this->inputHandler = inputHandler;
    this->gGenerator = gGenerator;
    gGenerator->generateGame(this);
}

GameLoop::~GameLoop() {
    deleteActors();
    deletePlayer();
    deleteBots();
    delete field;
    delete localPlayer;
    delete inputHandler;
}

void GameLoop::deleteActors() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++) {
        delete (*it);
    }
}

void GameLoop::deleteBots() {
    vector<Player*>::iterator it;
    for (it = bots.begin(); it < bots.end(); it++)
    {
        delete (*it);
    }
}

void GameLoop::deletePlayer() {
    vector<Player*>::iterator it;
    for (it = player.begin(); it < player.end(); it++)
    {
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
}

void GameLoop::setRespawTime(int respawnTime) {
    this->respawnTime = respawnTime;
}

void GameLoop::setGameField(GameField* newField) {
    this->field = newField;
}

void GameLoop::run()
{
    ms_per_update = 60;
    running = true;
    QTime t;
    int lag = 0;

    emit ping("start");
    t.start();

    while (running)
    {
        lag += t.elapsed();
        t.restart();
        processInput();
        while (running && lag >= ms_per_update) {
            update();
            lag -= ms_per_update;
        }
        render();
    }
}

void GameLoop::stop()
{
    running = false;
    emit ping("stop");
}

void GameLoop::processInput()
{
    set<int> codes = inputHandler->getInputs();
    for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
        execLocalPlayerAction(*it);
    }
}

void GameLoop::execLocalPlayerAction(int code)
{
    if (code == Qt::Key_Left) {
        localPlayer->applyForce(Vec3f(-0.01,0.,0.));
    } else if (code == Qt::Key_Up) {
        localPlayer->applyForce(Vec3f(0.,-0.01,0.));
    } else if (code == Qt::Key_Right) {
        localPlayer->applyForce(Vec3f(0.01,0.,0.));
    } else if (code == Qt::Key_Down) {
        localPlayer->applyForce(Vec3f(0.,0.01,0.));
    } else if (code == Qt::Key_W) {
        qDebug() << "Shoot Up";
    } else if (code == Qt::Key_S) {
        qDebug() << "Shoot Down";
    } else if (code == Qt::Key_A) {
        qDebug() << "Shoot Left";
    } else if (code == Qt::Key_D) {
        qDebug() << "Shoot Right";
    }
}

void GameLoop::update()
{
    qDebug() << "GameLoop: update";
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->update(actors);
    }
    for(it = actors.begin(); it != actors.end(); it++) {
        if ((*it)->isKilled() && (*it) != localPlayer) {
            delete (*it);
            actors.erase(it);
        }
    }
    actors.shrink_to_fit();
    QThread::msleep(5);
}


void GameLoop::render()
{
    qDebug() << "GameLoop: render";
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        vector<GameActor*>::iterator it;
        for(it = actors.begin(); it != actors.end(); it++) {
            GameActorView *view = (*it)->getView();
            viewlist->push_back(view);
        }
        emit renderObject(viewlist);
        QThread::msleep(5);
    } else {
        stop();
    }
}
