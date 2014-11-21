#include "headers/Game.h"
#include "headers/GameActorView.h"
#include <QDebug>

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
    string t = result;
    qDebug() << engine;

    //GameActorView view;
    //view.render(engine, qmlParent);
}

void Game::render(vector<GameActorView*> *views)
{
    //qDebug() << views;
    //views->at(0)->render(engine, qmlParent);
    //QQmlComponent component(engine, QUrl(QStringLiteral("qrc:/qml/CreditsSubMenu.qml")));
    QString path = QString::fromStdString(views->at(0)->getQmlPath());
    QQmlComponent component(engine, QUrl(path));
    QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
    childItem->setParentItem(qmlParent);
    //return childItem;
}
