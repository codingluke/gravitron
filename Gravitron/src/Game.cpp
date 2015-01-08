#include "headers/Game.h"
#include "headers/GameActorView.h"
#include "headers/InputHandler.h"
#include "headers/NetworkInputHandler.h"

#include <QDebug>
#include <iostream>

using namespace std;

Game::Game(QObject *parent) : QObject(parent)
{
}

Game::Game(QQmlApplicationEngine *theEngine, GravitronSettings *theSettings)
{
    engine = theEngine;
    settings = theSettings;
}

/**
 * Setter for the QQuickItem which acts as the same scene.
 *
 * @param theQmlParent
 */
void Game::setQmlParent(QQuickItem *theQmlParent)
{
    qmlParent = theQmlParent;
}

/**
 * Initializes the GameLoop in a own thread and connects the singnals/slots.
 */
void Game::start()
{
    InputHandler *iHandler = new InputHandler();
    gameLoop = new GameLoop(iHandler, new GameGenerator(settings));
    QCoreApplication::instance()->installEventFilter(iHandler);
    //connect(this, SIGNAL(stop(void)),
            //gameLoop, SLOT(stop(void)));
    //connect(this, SIGNAL(stop(void)),
            //this, SLOT(reset(void)));
    connect(gameLoop, SIGNAL(ping(string)),
            this, SLOT(handleResults(string)));
    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
            this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(activeWapponGame(int)),
            this, SLOT(setActiveWappon(int)));
    gameLoop->start();
}

void Game::start(TcpClient *client)
{
    qDebug() << "Game: start client";
    NetworkInputHandler *iHandler = new NetworkInputHandler(client);
    QCoreApplication::instance()->installEventFilter(iHandler);
    gameLoop->start();
}

void Game::start(TcpServer *server)
{
    qDebug() << "Game: start server";
    NetworkInputHandler *iHandler = new NetworkInputHandler(server);
    QCoreApplication::instance()->installEventFilter(iHandler);
    gameLoop->start();
}

void Game::stop()
{
    gameLoop->stop();
    gameLoop->quit();
    gameLoop->wait();
    delete gameLoop;
}

//void Game::init() {
    //init(NULL);
//}

//void Game::init()
//{
    //InputHandler *iHandler = new InputHandler();
    //gameLoop = new GameLoop(iHandler, new GameGenerator(settings));
    //QCoreApplication::instance()->installEventFilter(iHandler);
    //connect(this, SIGNAL(stop(void)),
            //gameLoop, SLOT(stop(void)));
    //connect(gameLoop, SIGNAL(ping(string)),
            //this, SLOT(handleResults(string)));
    //connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
            //this, SLOT(render(vector<GameActorView*>*)));
    //connect(gameLoop, SIGNAL(activeWapponGame(int)),
            //this, SLOT(setActiveWappon(int)));
//}

Game::~Game()
{
    stop();
    //gameLoop->quit();
    //gameLoop->wait();
    //delete gameLoop;
}

void Game::handleResults(const string &result)
{
    qDebug() << QString::fromStdString(result);
}

/**
 * Deletes all the child items of qmlParent with a valid "identifier" property.
 * The "identifier" property is a self defined property to identify
 * self created QQuickItems.
 */
void Game::clearScene()
{
    QList<QQuickItem*> children = qmlParent->childItems();
    QListIterator<QQuickItem*> itc(children);
    while (itc.hasNext())
    {
        QQuickItem *itm = itc.next();
        if (itm->property("identifier").isValid())
            delete itm;
    }
}

/**
 * Creates a QQuickItem for each element in the views list and
 * adds their special properties.
 *
 * IMPORTANT! The list and its content gets deleted from the heap!
 *
 * @param views pointer to a vector of pointers to GameActorView's
 */
void Game::render(vector<GameActorView*> *views)
{
    clearScene();
    vector<GameActorView*>::iterator it;
    for (it = views->begin(); it < views->end(); it++)
    {
        // Create Object from QML and set its parent
        QString path = QString::fromStdString((*it)->getQmlPath());
        QQmlComponent component(engine, QUrl(path));
        QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
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

void Game::setActiveWappon(int wapponNumber) {
    if(wapponNumber == 1) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(true));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(false));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(false));
    } else if (wapponNumber == 2 ) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(false));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(true));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(false));
    } else if (wapponNumber == 3 ) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(false));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(false));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(true));
    }
}
