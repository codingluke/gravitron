#include "headers/Game.h"
#include "headers/GameActorView.h"
#include "headers/InputHandler.h"
#include "headers/NetworkInputHandler.h"
#include <sstream>
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
    gameLoop = NULL;
    field = NULL;
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
    field = new GameField(2000 , 2000);
    settings->setNetwork(false);
    gameLoop = new GameLoop(GameGenerator(settings, field));
    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
        this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(activeWeaponGame(int)),
        this, SLOT(setActiveWeapon(int)));
    connect(gameLoop, SIGNAL(lifepoints(int)),
        this, SLOT(setLifepoints(int)));
    connect(gameLoop, SIGNAL(backgroundPos(float, float, float, float)),
        this, SLOT(setBackgroundPosition(float, float, float, float)));
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
    field = new GameField(2000 , 2000);
    settings->setNetwork(true);
    gameLoop = new GameLoop(GameGenerator(settings, field, server));

    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
        this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(sendViewlist(QString)),
        server, SLOT(transfer(QString)));
    connect(gameLoop, SIGNAL(lifepoints(int)),
        this, SLOT(setLifepoints(int)));
    connect(gameLoop, SIGNAL(activeWeaponGame(int)),
        this, SLOT(setActiveWeapon(int)));

    gameLoop->start();
    gameLoop->setPriority(QThread::LowPriority);
}

void Game::stop()
{
    if (gameLoop) {
        gameLoop->stop();
        while(!gameLoop->isFinished()){} // dirty hack!
            delete gameLoop;
        gameLoop = NULL;
        delete field;
    }
}

Game::~Game()
{
    stop();
}

/**
 * Deletes all the child items of qmlParent with a valid "identifier" property.
 * The "identifier" property is a self defined property to identify
 * self created QQuickItems.
 */
 void Game::clearScene(vector<GameActorView*> *views)
 {
    vector<GameActorView*>::iterator it;
    QList<QQuickItem*> children = qmlParent->childItems();
    QListIterator<QQuickItem*> itc(children);
    while (itc.hasNext()) {
        QQuickItem *itm = itc.next();
        QVariant id = itm->property("identifier");
        if (id.isValid()) {
            bool exists = false;
            for (it = views->begin(); !exists && it < views->end(); it++) {
                if ((*it)->getProperties()["identifier"] ==
                    id.toString().toStdString()) {
                    exists = true;
                }
            }
            if (!exists) {
                delete itm;
            }
        } else if (itm->property("objectName").toString() == "Infobox") {
            itm->setProperty("visible", false);
        }
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
    // qDebug() << serializedViewlist << "\n";
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
        } else if (vList.at(i).startsWith("clifepoints")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setLifepoints(vL.at(vL.size() - 1).toInt());
        } else if (vList.at(i).startsWith("cweapon")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setActiveWeapon(vL.at(vL.size() - 1).toInt());
        } else if (vList.at(i).startsWith("xbackgroundPos")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setBackgroundPosition(vL.at(vL.size() - 4).toInt(), vL.at(vL.size() - 3).toInt(), 
                vL.at(vL.size() - 2).toInt(), vL.at(vL.size() - 1).toInt());
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
    window_width = qmlParent->width();
    window_height = qmlParent->height();
    clearScene(views);
    vector<GameActorView*>::iterator it;
    for (it = views->begin(); it < views->end(); it++)
    {
        setRelativePosition(window_width / 2, window_height / 2, *it);
        map<string, string> props = (*it)->getProperties();
        map<string, string>::iterator pit;
        QString id = QString::fromStdString(props["identifier"]);
        QObject *item = qmlParent->findChild<QQuickItem*>(id);
        if (item) {
            // Map the properties
            for(pit = props.begin(); pit != props.end(); pit++) {
                item->setProperty(pit->first.c_str(), pit->second.c_str());
            }
        } else {
            // Create Object from QML and set its parent
            QString path = QString::fromStdString((*it)->getQmlPath());
            QQmlComponent component(engine, QUrl(path));
            QQuickItem *childItem = qobject_cast<QQuickItem*>(component.create());
            childItem->setParent(qmlParent);
            childItem->setParentItem(qmlParent);
            // Map the properties
            for(pit = props.begin(); pit != props.end(); pit++) {
                childItem->setProperty(pit->first.c_str(), pit->second.c_str());
            }
        }
        delete (*it);
    }
    delete views;
}

void Game::setBackgroundPosition(float x, float y, float fieldWidth, float fieldHeight)
{
    QQuickItem *background = qmlParent->findChild<QQuickItem*>("background");
    background->setProperty("x", window_width / 2 - x);
    background->setProperty("y", window_height / 2 - y);
    background->setProperty("width", fieldWidth);
    background->setProperty("height", fieldHeight);
}

void Game::setLifepoints(int lifepoints)
{
    QQuickItem *statusBar = qmlParent->findChild<QQuickItem*>("gameStatus");
    statusBar->setProperty("lifepoints", lifepoints);
}

void Game::setActiveWeapon(int weaponNumber)
{
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

void Game::setRelativePosition(float anchor_x, float anchor_y, GameActorView *view)
{
    float x;
    std::stringstream sstr_x;
    sstr_x << view->getPropterty("x");
    sstr_x >> x;
    std::ostringstream ostr_x;
    x = anchor_x - x;
    ostr_x << x;
    view->setProperty("x", ostr_x.str());
    float y;
    std::stringstream sstr_y;
    sstr_y << view->getPropterty("y");
    sstr_y >> y;
    y = anchor_y - y;
    std::ostringstream ostr_y;
    ostr_y << y;
    view->setProperty("y", ostr_y.str());
}
