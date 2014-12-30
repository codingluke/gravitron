#include "headers/Game.h"
#include "headers/GameActorView.h"
#include "headers/InputHandler.h"

#include <QDebug>
#include <iostream>

using namespace std;

Game::Game(QObject *parent) : QObject(parent)
{
    init();
}

Game::Game(QQmlApplicationEngine *theEngine, GameGenerator *gGenerator)
{
    engine = theEngine;
    init(gGenerator);
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
    gameLoop->start();
}

void Game::init() {
    init(NULL);
}

void Game::init(GameGenerator *gGenerator)
{
    InputHandler *iHandler = new InputHandler();
    gameLoop = new GameLoop(iHandler, gGenerator);
    QCoreApplication::instance()->installEventFilter(iHandler);
    connect(this, SIGNAL(stop(void)),
            gameLoop, SLOT(stop(void)));
    connect(gameLoop, SIGNAL(ping(string)),
            this, SLOT(handleResults(string)));
    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
            this, SLOT(render(vector<GameActorView*>*)));
}

Game::~Game()
{
    gameLoop->quit();
    gameLoop->wait();
    delete gameLoop;
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
