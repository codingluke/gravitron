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


GameLoop::GameLoop(InputHandler *inputHandler, GameGenerator gGenerator)
{
    this->inputHandler = inputHandler;
    gGenerator.generateGame(this);
}

GameLoop::~GameLoop() {
    deleteActors();
    deletePlayer();
    deleteBots();
    //delete field;
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
    ms_per_update = 60;
    running = true;
    QTime t;
    int lag = 0;

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
}

void GameLoop::processInput()
{
    player[0]->processInput();
    //set<int> codes = inputHandler->getInputs();
    //for(set<int>::iterator it = codes.begin(); it != codes.end(); it++) {
        //execLocalPlayerAction(*it);
    //}
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
        actors.push_back(&(localPlayer->Spacecraft::shootUp()));
        inputHandler->removeInputCode(Qt::Key_W);
    } else if (code == Qt::Key_S) {
        actors.push_back(&(localPlayer->Spacecraft::shootDown()));
        inputHandler->removeInputCode(Qt::Key_S);
    } else if (code == Qt::Key_A) {
        actors.push_back(&(localPlayer->Spacecraft::shootLeft()));
        inputHandler->removeInputCode(Qt::Key_A);
    } else if (code == Qt::Key_D) {
        actors.push_back(&(localPlayer->Spacecraft::shootRight()));
        inputHandler->removeInputCode(Qt::Key_D);
    } else if (code == Qt::Key_1) {
        emit activeWeaponGame(1);
        emit activeWeaponPlayer(1);
    } else if (code == Qt::Key_2) {
        emit activeWeaponGame(2);
        emit activeWeaponPlayer(2);
    } else if (code == Qt::Key_3) {
        emit activeWeaponGame(3);
        emit activeWeaponPlayer(3);
    }
}

void GameLoop::update()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->updateAll();
        //(*it)->update(actors);
    }
    for (int i = 0; i < (int) actors.size(); i++)
    {
        if((actors[i]->isKilled()) && (actors[i] != localPlayer))
        {
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
