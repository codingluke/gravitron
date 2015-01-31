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

Game::Game(QQmlApplicationEngine *theEngine, GravitronSettings *theSettings,
           TcpClient *client, TcpServer *server)
{
    engine = theEngine;
    settings = theSettings;
    this->server = server;
    this->client = client;
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
    field = new GameField(2000 * settings->playingFieldSacleFactor() , 1300 * settings->playingFieldSacleFactor());
    settings->setMultiplayer(false);
    gameLoop = new GameLoop(GameGenerator(settings, field));
    connectGameloop();
    gameLoop->start();
}

/**
 * Starts the client. The Inputhandler signals are connected to the tcp socket. and
 * the tcp inputs are connected to the renderRemote Action
 */
void Game::startClient()
{
    InputHandler *iHandler = new InputHandler();
    QCoreApplication::instance()->installEventFilter(iHandler);

    connect(iHandler, SIGNAL(inputsChanged(set<int>)),
        client, SLOT(transfer(set<int>)));
    connect(client, SIGNAL(received(QString)),
        this, SLOT(renderRemote(QString)));
}

/**
 * starts the Server. A Gamefield and the GameLoop is instatiated.
 * All the necessary signals are connected from the gameloop to the game.
 * It signals to the client, that the game has started, so that the client
 * can send his username.
 */
void Game::startServer()
{
    field = new GameField(2000 * settings->playingFieldSacleFactor(),
                          1300 * settings->playingFieldSacleFactor());
    settings->setMultiplayer(true);
    gameLoop = new GameLoop(GameGenerator(settings, field, server));
    connectGameloop();
    connect(gameLoop, SIGNAL(sendViewlist(QString)),
        server, SLOT(transfer(QString)));
    gameLoop->start();
    gameLoop->setPriority(QThread::LowPriority);
    server->transfer("cstart\n");
}

/**
 * Connects all the necessary signals from the gameloop to the game.
 */
void Game::connectGameloop()
{
    connect(gameLoop, SIGNAL(renderObject(vector<GameActorView*>*)),
        this, SLOT(render(vector<GameActorView*>*)));
    connect(gameLoop, SIGNAL(lifepoints(int)),
        this, SLOT(setLifepoints(int)));
    connect(gameLoop, SIGNAL(activeWeaponGame(int)),
        this, SLOT(setActiveWeapon(int)));
    connect(gameLoop, SIGNAL(backgroundPos(float, float, float, float)),
        this, SLOT(setBackgroundPosition(float, float, float, float)));
    connect(gameLoop, SIGNAL(theWinnerIs(QString)),
        this, SLOT(setInfoboxMessage(QString)));
    connect(gameLoop, SIGNAL(fragStatus(int, int)),
        this, SLOT(setFrag(int, int)));
}

/**
 * Stops the gameloop and deletes also the field.
 */
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

/**
 * Destructor, stops the current game.
 */
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
        }
    }
}

/**
 * Deserializes the serialized Views, generates a viewlist and sends them
 * to the render method.
 *
 * @param serializedViewlist Qstring of the serializedViewlist over the network.
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
        } else if (vList.at(i).startsWith("clifepoints")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setLifepoints(vL.at(vL.size() - 1).toInt());
        } else if (vList.at(i).startsWith("cweapon")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setActiveWeapon(vL.at(vL.size() - 1).toInt());
        } else if (vList.at(i).startsWith("cbackgroundPos")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setBackgroundPosition(vL.at(vL.size() - 4).toFloat(), vL.at(vL.size() - 3).toFloat(),
                vL.at(vL.size() - 2).toFloat(), vL.at(vL.size() - 1).toFloat());
        } else if (vList.at(i).startsWith("cwinner")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            setInfoboxMessage(vL.at(vL.size() - 1));
        } else if (vList.at(i).startsWith("cfrag")) {
            QStringList vL = vList.at(i).split(":", QString::SkipEmptyParts);
            vL = vL.at(vL.size() - 1).split(",", QString::SkipEmptyParts);
            setFrag(vL.at(0).toInt(), vL.at(1).toInt());
        } else if (vList.at(i).startsWith("cstart")) {
            client->transfer("cname:" + settings->playerName() + "\n");
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
    setInfoboxMessage("");
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


/**
 * Sets the Frag status in the QML GUI.
 *
 * @param must  Must frag level
 * @param have  Have frag level
 */
void Game::setFrag(int must, int have)
{
    QQuickItem *fragStatus = qmlParent->findChild<QQuickItem*>("fragStatus");
    fragStatus->setProperty("must", must);
    fragStatus->setProperty("have", have);
}

/**
 * Sets the Backgroundposition new, according to the spaceship of the player.
 *
 * @param x             x position of the field
 * @param y             y position of the field
 * @param fieldWidth    width of the field
 * @param fieldHeight   height of the field
 */
void Game::setBackgroundPosition(float x, float y, float fieldWidth, float fieldHeight)
{
    QQuickItem *background = qmlParent->findChild<QQuickItem*>("background");
    background->setProperty("x", window_width / 2 - x);
    background->setProperty("y", window_height / 2 - y);
    background->setProperty("width", fieldWidth);
    background->setProperty("height", fieldHeight);
}

/**
 * Sets the lifepoints in the QML GUI.
 *
 * @param lifepoints  Lifepoints in percentage
 */
void Game::setLifepoints(int lifepoints)
{
    QQuickItem *statusBar = qmlParent->findChild<QQuickItem*>("gameStatus");
    statusBar->setProperty("lifepoints", lifepoints);
}

/**
 * Shows a infomessage in the QMO Gui.
 *
 * @param message   Message to be shown.
 */
void Game::setInfoboxMessage(QString message)
{
    QObject *infoBox = qmlParent->findChild<QQuickItem*>("Infobox");
    if (message == "") {
        infoBox->setProperty("visible", false);
    } else {
        infoBox->setProperty("visible", true);
        infoBox->setProperty("text", message);
    }
}

/**
 * Sets the active Weapon in the QML Gui.
 *
 * @param weaponNumber number of the Weapon.
 */
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

/**
 * Helper method to find out a relative position of a GameActorView according
 * an anchor.
 *
 * @param anchor_x    x anchor
 * @param anchor_y    y anchor
 * @param view        GameActorView to calculate the relative position
 */
void Game::setRelativePosition(float anchor_x, float anchor_y, GameActorView *view)
{
    float x;
    std::stringstream sstr_x;
    sstr_x << view->getPropterty("x");
    sstr_x >> x;
    x = anchor_x - x;
    view->setProperty("x", x);
    float y;
    std::stringstream sstr_y;
    sstr_y << view->getPropterty("y");
    sstr_y >> y;
    y = anchor_y - y;
    view->setProperty("y", y);
}
