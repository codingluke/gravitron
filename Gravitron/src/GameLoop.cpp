#include "headers/GameLoop.h"
#include "headers/Spacecraft.h"
#include "headers/Projectile.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>
#include <QAbstractEventDispatcher>
#include <cstdlib>

using namespace std;


GameLoop::GameLoop()
{
    field = new GameField(500, 500);
    for (int i = 0; i < 1; i++) {
        Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
        float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        float gravitationRange =  rand() % 200 + 1;
        float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
        GameActor* actor = new GameActor(position, mass, gravitationRange, g, *field);
        actors.push_back(actor);
    }
    Vec3f position(rand() % field->getWidth(),rand() % field->getHeight(), 0);
    float mass = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    actors.push_back(new Spacecraft(position, mass, 0, 0, *field));
}

GameLoop::~GameLoop() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++)
    {
        delete (*it);
    }
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

void GameLoop::inputEvents(int code)
{
    qDebug() << code;
    inputs = code;
}

bool GameLoop::eventFilter(QObject *obj, QEvent *event)
{
  if (event->type() == QEvent::KeyPress && obj)
  {
    QKeyEvent *keyEvent = (QKeyEvent*)event;
    inputs = keyEvent->key();
    qDebug() << inputs;
  }
  return false;
}

void GameLoop::stop()
{
    running = false;
    emit ping("stop");
}

void GameLoop::processInput()
{
    if (inputs == 16777234) {
        // left
        actors[actors.size() - 1]->applyForce(Vec3f(-0.01,0.,0.));
    } else if (inputs == 16777235) {
        // up
        actors[actors.size() - 1]->applyForce(Vec3f(0.,-0.01,0.));
    } else if (inputs == 16777236) {
        // right
        actors[actors.size() - 1]->applyForce(Vec3f(0.01,0.,0.));
    } else if (inputs == 16777237) {
        // down
        actors[actors.size() - 1]->applyForce(Vec3f(0.,0.01,0.));
    }
    inputs = 0;
}

void GameLoop::update()
{
    //applyGravitationToAllActor();
    updateAllActors();
}

void GameLoop::render()
{
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        for (unsigned int i = 0; i < actors.size(); i++) {
            GameActorView *view = actors[i]->getView();
            viewlist->push_back(view);
        }
        emit renderObject(viewlist);
        QThread::msleep(5);
    } else {
        stop();
    }
}

void GameLoop::updateAllActors() {
    for (unsigned int i = 0; i < actors.size(); i++) {
        actors[i]->update(actors);
    }
}
