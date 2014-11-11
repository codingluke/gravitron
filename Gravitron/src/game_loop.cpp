#include "game_loop.h"
#include <iostream>
#include <iomanip>
#include <QTime>

using namespace std;

void GameLoop::doWork()
{
    ms_per_update = 60.0;
    running = true;
    double previous = getCurrentTime();
    double lag = 0.0;

    emit ping("start");
    while (running)
    {
        double current = getCurrentTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        processInput();

        while (running && lag >= ms_per_update)
        {
            update();
            lag -= ms_per_update;
        }
        render();
        emit ping("run");
        QThread::msleep(200);
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
    //cout << "render!";
}

double GameLoop::getCurrentTime()
{
    return QTime::currentTime().msec();
}
