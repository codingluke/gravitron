#include <QTime>
#include "headers/GameLoop.h"
#include <QDebug>

using namespace std;

GameLoop::GameLoop()
{
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
    vector<GameActorView*> *viewlist = new vector<GameActorView*>;
    GameActorView *view = new GameActorView("qrc:/qml/actor");
    view->setProperty("identifier", "1");
    view->setProperty("color", "blue");
    view->setProperty("x", "100");

    GameActorView *view2 = new GameActorView("qrc:/qml/actor");
    view2->setProperty("identifier", "2");
    view2->setProperty("y", "40");
    view2->setProperty("color", "white");
    view2->setProperty("width", "100");
    viewlist->push_back(view);
    viewlist->push_back(view2);
    emit renderObject(viewlist);
    QThread::msleep(100);
}
