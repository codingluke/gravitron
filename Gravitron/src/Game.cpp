#include "headers/Game.h"
#include <iostream>

using namespace std;

Game::Game(QObject *parent) : QObject(parent)
{
  init();
}

void Game::init()
{
    GameLoop *worker = new GameLoop;
    worker->moveToThread(&workerThread);
    connect(this, SIGNAL(start(void)),
            worker, SLOT(doWork(void)));
    connect(this, SIGNAL(stop(void)),
            worker, SLOT(stop(void)), Qt::DirectConnection);
    connect(worker, SIGNAL(ping(string)),
            this, SLOT(handleResults(string)));
    workerThread.start();
}

Game::~Game()
{
    workerThread.quit();
    workerThread.wait();
}

void Game::handleResults(const string &result)
{
    cout << result << "\n";
    cout.flush();
}
