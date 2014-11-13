#include <iostream>
#include <iomanip>
#include <QTime>
#include "headers/GameLoop.h"

using namespace std;

void GameLoop::doWork()
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
            cout << lag << "\n";
        }
        render();
        emit ping("round finished");
    }
    emit ping("fertig");
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
}

void GameLoop::render()
{
    QThread::msleep(100);
    //cout << "render!";
}

int GameLoop::getCurrentTime()
{
    return QTime::currentTime().msec();
}
