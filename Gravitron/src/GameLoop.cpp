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


GameLoop::GameLoop(InputHandler *inputHandler)
{
    this->inputHandler = inputHandler;
    field = new GameField(500, 500);
    for (int i = 0; i < 4; i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float gravitationRange =  rand() % 200 + 1;
        float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        GameActor* actor = new GameActor(position, mass, gravitationRange, g, 100, *field, 5);
        actors.push_back(actor);
    }
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    localPlayer = new Spacecraft(position, mass, 0, 0, 100, *field, 10);
    actors.push_back(localPlayer);
}

GameLoop::~GameLoop() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++)
    {
        delete (*it);
    }
    delete field;
    delete localPlayer;
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

        while (running && lag >= ms_per_update)
        {
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
        //actors.push_back(new Laser(*localPlayer, Vec3f(0.,-0.01,0.), *field, *localPlayer));
        //actors.push_back(new Laser(localPlayer->getPosition() + Vec3f(-2.,-2.,0.), Vec3f(0.,-0.01,0.), *field, *localPlayer));
        Projectile *shot = new Projectile(localPlayer->Spacecraft::shootUp());
        actors.push_back(shot);
        inputHandler->removeInputCode(Qt::Key_W);
        //qDebug() << "Shoot Up";
    } else if (code == Qt::Key_S) {
        Projectile *shot = new Projectile(localPlayer->Spacecraft::shootDown());
        actors.push_back(shot);
        inputHandler->removeInputCode(Qt::Key_S);
        //actors.push_back(new Laser(*localPlayer, Vec3f(0.,0.01,0.), *field, *localPlayer));
        //qDebug() << "Shoot Down";
    } else if (code == Qt::Key_A) {
        Projectile *shot = new Projectile(localPlayer->Spacecraft::shootLeft());
        actors.push_back(shot);
        inputHandler->removeInputCode(Qt::Key_A);
        //actors.push_back(new Laser(*localPlayer, Vec3f(-0.01,0.,0.), *field, *localPlayer));
        //qDebug() << "Shoot Left";
    } else if (code == Qt::Key_D) {
        Projectile *shot = new Projectile(localPlayer->Spacecraft::shootRight());
        actors.push_back(shot);
        inputHandler->removeInputCode(Qt::Key_D);
        //actors.push_back(new Laser(*localPlayer, Vec3f(0.01,0.,0.), *field, *localPlayer));
        //qDebug() << "Shoot Right";
    }
}

void GameLoop::update()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->update(actors);
    }
    for(it = actors.begin(); it != actors.end(); it++) {
        if ((*it)->isKilled() && (*it) != localPlayer) {
            qDebug() << "kill";
            delete (*it);
            actors.erase(it);
        }
    }
    actors.shrink_to_fit();
}

void GameLoop::render()
{
    qDebug() << actors.size();
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        vector<GameActor*>::iterator it;
        for(it = actors.begin(); it != actors.end(); it++) {
        //for (unsigned int i = 0; i < actors.size(); i++) {
            //GameActorView *view = actors[i]->getView();
            GameActorView *view = (*it)->getView();
            //qDebug() << "hallo";
            viewlist->push_back(view);
        }
        emit renderObject(viewlist);
        QThread::msleep(5);
    } else {
        stop();
    }
}
