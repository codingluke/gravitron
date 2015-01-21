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
    field = new GameField(1000 , 1000);
    gameLoop = new GameLoop(GameGenerator(settings, field));

    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
            this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(activeWeaponGame(int)),
            this, SLOT(setActiveWeapon(int)));
    gameLoop->start();
}

void Game::startClient(TcpClient *client)
{
    qDebug() << "Game: start client";
    InputHandler *iHandler = new InputHandler();
    QCoreApplication::instance()->installEventFilter(iHandler);

    connect(iHandler, SIGNAL(inputsChanged(set<int>)),
            client, SLOT(transfer(set<int>)));
    connect(client, SIGNAL(received(QString)),
            this, SLOT(renderRemote(QString)));
}

void Game::startServer(TcpServer *server)
{
    qDebug() << "Game: start server";
    field = new GameField(1000 , 1000);
    settings->setNetwork(true);
    gameLoop = new GameLoop(GameGenerator(settings, field, server));

    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
            this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(activeWeaponGame(int)),
            this, SLOT(setActiveWeapon(int)));
    connect(gameLoop, SIGNAL(sendViewlist(QString)),
            server, SLOT(transfer(QString)));

    gameLoop->start();
}

void Game::stop()
{
    gameLoop->stop();
    //Stop is doing the jop
    //gameLoop->quit();
    //gameLoop->wait();
    //delete gameLoop;
}

Game::~Game()
{
    stop();
    delete field;
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
 * Deserializes the serialized Views, generates a viewlist and sends them
 * to the render method.
 *
 * @param Qstring of the serializedViewlist over the network.
 */
void Game::renderRemote(QString serializedViewlist)
{
    QStringList vList = serializedViewlist.split("\n", QString::SkipEmptyParts);
    for (int i = 0; i < vList.size(); ++i) {
        if (vList.at(i).startsWith("v")) {
            vector<GameActorView*> *viewlist = new vector<GameActorView*>;
            QStringList vL = vList.at(i).split(";", QString::SkipEmptyParts);
            for (int j = 0; j < vL.size(); ++j) {
                GameActorView *v = new GameActorView();
                v->fromString(vL.at(j).toStdString());
                viewlist->push_back(v);
            }
            render(viewlist);
        }
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

void Game::setActiveWeapon(int weaponNumber) {
    if(weaponNumber == 1) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(true));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(false));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(false));
    } else if (weaponNumber == 2 ) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(false));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(true));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(false));
    } else if (weaponNumber == 3 ) {
        QQuickItem *laser = qmlParent->findChild<QQuickItem*>("rec_selectLaser");
        laser->setProperty("focus",QVariant(false));
        QQuickItem *missile = qmlParent->findChild<QQuickItem*>("rec_selectMissile");
        missile->setProperty("focus",QVariant(false));
        QQuickItem *aimMissile = qmlParent->findChild<QQuickItem*>("rec_selectAimMissile");
        aimMissile->setProperty("focus",QVariant(true));
    }
}
