#include "headers/Game.h"
#include "headers/GameActorView.h"
#include <QDebug>
#include <iostream>

using namespace std;

Game::Game(QObject *parent) : QObject(parent)
{
  init();
}

Game::Game(QQmlApplicationEngine *theEngine)
{
  engine = theEngine;
  init();
}

void Game::setQmlParent(QQuickItem *theQmlParent)
{
    qmlParent = theQmlParent;
}

void Game::init()
{
    GameLoop *worker = new GameLoop();
    worker->moveToThread(&workerThread);
    connect(this, SIGNAL(start(void)),
            worker, SLOT(run(void)));
    connect(this, SIGNAL(stop(void)),
            worker, SLOT(stop(void)), Qt::DirectConnection);
    connect(worker, SIGNAL(ping(string)),
            this, SLOT(handleResults(string)));
    connect(worker, SIGNAL(renderObject(vector<GameActorView*>*)),
            this, SLOT(render(vector<GameActorView*>*)));
    workerThread.start();
}

Game::~Game()
{
    workerThread.quit();
    workerThread.wait();
}

void Game::handleResults(const string &result)
{
    qDebug() << QString::fromStdString(result);
}

  void Game::render(vector<GameActorView*> *views)
  {
    // Renders all the views and deletes them out of the vector
    vector<GameActorView*>::iterator it;
    for (it = views->begin(); it < views->end(); it++)
    {
        // Create Object from QML
        QString path = QString::fromStdString((*it)->getQmlPath());
        QQmlComponent component(engine, QUrl(path));
        QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());

        // Map the GameScene as parent
        childItem->setParentItem(qmlParent);

        // Map the properties
        map<string, string> props = (*it)->getProperties();
        map<string, string>::iterator pit;
        for(pit = props.begin(); pit != props.end(); pit++) {
            childItem->setProperty(pit->first.c_str(), pit->second.c_str());
        }
        delete (*it);
    }
    delete views;
}
