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
    //emit ping("stop");
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
    GameActorView *view = new GameActorView("qrc:/qml/CreditsSubMenu.qml");
    GameActorView *view2 = new GameActorView("qrc:/qml/NewGameSubMenu.qml");
    viewlist->push_back(view);
    viewlist->push_back(view2);
    emit renderObject(viewlist);
    QThread::msleep(100);
    //cout << "render!";
}
