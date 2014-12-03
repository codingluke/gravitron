#include "headers/GameLoop.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;


GameLoop::GameLoop()
{
    Vec3f position(1.,1.,1.);
    Vec3f force(0.5,0.5,0.5);
    double mass = 1.3;
    GameActor actor1(position, mass);
    actor1.applyForce(force);
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

void GameLoop::stop()
{
    running = false;
    emit ping("stop");
}

void GameLoop::processInput()
{
    //cout << "processInput!";
}

void GameLoop::update()
{
    //emit ping("update!");
    //qDebug() << game;
}

void GameLoop::render()
{

    // Change color by time :)
    //QTime::current_time()
    //float time = (float) QTime::currentTime().msec();
    //QString x = QString::number(time);

    vector<GameActorView*> *viewlist = new vector<GameActorView*>;
    GameActorView *view = actors[0].getView();
    actors[0].update();
    viewlist->push_back(view);
    emit renderObject(viewlist);
    QThread::msleep(20);
}
