#include "headers/GameLoop.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>
#include <QAbstractEventDispatcher>

using namespace std;


GameLoop::GameLoop()
{
    Vec3f position(1.,1.,1.);
    //Vec3f force(0.5,0.5,0.5);
    double mass = 1.3;
    GameActor actor1(position, mass);
    //actor1.applyForce(force);
    actors.push_back(actor1);
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
        actors[0].applyForce(Vec3f(-0.01,0.,0.));
    } else if (inputs == 16777235) {
        // up
        actors[0].applyForce(Vec3f(0.,-0.01,0.));
    } else if (inputs == 16777236) {
        // right
        actors[0].applyForce(Vec3f(0.01,0.,0.));
    } else if (inputs == 16777237) {
        // down
        actors[0].applyForce(Vec3f(0.,0.01,0.));
    }
    inputs = 0;
}

void GameLoop::update()
{
    actors[0].update();
}

void GameLoop::render()
{
    vector<GameActorView*> *viewlist = new vector<GameActorView*>;
    GameActorView *view = actors[0].getView();
    viewlist->push_back(view);
    emit renderObject(viewlist);
    QThread::msleep(5);
}

void GameLoop::applyGravitationToAllActor() {
    std::vector<GameActor>::iterator itOuter = actors.begin();
    for (itOuter ; itOuter != actors.end(); ++itOuter) {
        std::vector<GameActor>::iterator itInner = actors.begin();
        for (itInner ; itInner != actors.end(); ++itInner) {
            (*itInner).applyForce(Physics::calculateGravitationForce((*itOuter),(*itInner)));
        }
    }
}
