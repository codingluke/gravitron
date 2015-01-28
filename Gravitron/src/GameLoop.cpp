#include "headers/GameLoop.h"
#include "headers/Spacecraft.h"
#include "headers/Projectile.h"
#include "headers/InputHandler.h"
#include "headers/Laser.h"
#include "headers/HumanPlayer.h"
#include "headers/HumanNetworkPlayer.h"
#include <QTime>
#include <QDebug>
#include <math.h>
#include <string>
#include <iostream>
#include <QAbstractEventDispatcher>
#include <cstdlib>
#include <sstream>

using namespace std;


GameLoop::GameLoop(GameGenerator gGenerator)
{
    gGenerator.generateGame(this);
}

GameLoop::~GameLoop() {
    deleteActors();
    deletePlayer();
    deleteBots();
}

void GameLoop::deleteActors() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++) {
        delete (*it);
    }
}

void GameLoop::deleteBots() {
    vector<KiPlayer*>::iterator it;
    for (it = bots.begin(); it < bots.end(); it++) {
        delete (*it);
    }
}

void GameLoop::deletePlayer() {
    vector<Player*>::iterator it;
    for (it = player.begin(); it < player.end(); it++) {
        delete (*it);
    }
}

void GameLoop::setBots(vector<KiPlayer*> bots) {
    deleteBots();
    for (KiPlayer* kp : bots)
    {
        this->bots.push_back(kp);
    }
}

void GameLoop::setPlayer(vector<Player*> player) {
    deletePlayer();
    this->player = player;
    //this->localPlayer = this->player[0]->spacecraft;
}

void GameLoop::setActors(vector<GameActor*> actors) {
    deleteActors();
    this->actors = actors;
    remapActorsReferences();
}

void GameLoop::remapActorsReferences()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->setActors(&actors);
    }
}

void GameLoop::setRespawTime(int respawnTime) {
    this->respawnTime = respawnTime;
}

void GameLoop::setGameField(GameField* newField)
{
    this->field = newField;
}


void GameLoop::run()
{
    int lag = 0;
    ms_per_update = 30;
    running = true;
    QTime t;
    t.start();
    while (running)
    {
        t.restart();
        processInput();
        update();
        if(checkWinner()) {
            stop();
        } else {
            render();
        }
        lag = ms_per_update - t.elapsed();
        if (lag > 0) {
            QThread::msleep(lag);
        }
    }
}

void GameLoop::stop()
{
    running = false;
}

Player* GameLoop::checkWinner() const
{
    Player *winner = NULL;
    for (Player* p : player) {
        if (p->isWinner()) {
            winner = p;
        }
    }
    return winner;
}

void GameLoop::processInput()
{
    vector<Player*>::iterator it;
    for(it = player.begin(); it != player.end(); it++) {
      (*it)->processInput();
    }
}

void GameLoop::update()
{
    for(int i = 0; i < (int) actors.size(); i++) {
        actors[i]->updateAll();
    }
    for (int i = 0; i < (int) actors.size(); i++)
    {
        Spacecraft* isSpacecraft = NULL;
        isSpacecraft = dynamic_cast<Spacecraft*>(actors[i]);
        if((actors[i]->isKilled()) && (!isSpacecraft)) {
            delete (actors[i]);
            actors.erase(actors.begin() + i);
        }
    }
    actors.shrink_to_fit();
    for (int i = 0; i < bots.size(); i++){
        bots[i]->update();
    }

    QThread::msleep(5);
}

void GameLoop::render()
{
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        vector<GameActor*>::iterator it;
        QString serializedViewlist("v");
        std::ostringstream x;
        std::ostringstream y;
        for(it = actors.begin(); it != actors.end(); it++) {
            GameActorView *view = (*it)->getView();
            std::ostringstream x;
            std::ostringstream y;
            if (player.size() == 2)
            {
                x << getRelativePositionX(*(player[1]->getSpacecraft()), **it);
                y << getRelativePositionY(*(player[1]->getSpacecraft()), **it);
                view->setProperty("x", x.str());
                view->setProperty("y", y.str());
                serializedViewlist += QString::fromStdString(view->toString());
                serializedViewlist += ";";
                x.str("");
                y.str("");
                x << getRelativePositionX(*(player[0]->getSpacecraft()), **it);
                y << getRelativePositionY(*(player[0]->getSpacecraft()), **it);
                view->setProperty("x", x.str());
                view->setProperty("y", y.str());
                viewlist->push_back(view);
            }
            else
            {
                x << getRelativePositionX(*(player[0]->getSpacecraft()), **it);
                y << getRelativePositionY(*(player[0]->getSpacecraft()), **it);
                view->setProperty("x", x.str());
                view->setProperty("y", y.str());
                viewlist->push_back(view);
            }
        }
        serializedViewlist += "\n";
        vector<Player*>::iterator playit;
        GameActor bgrndUpperLeft = GameActor(Vec3f(0, 0, 0), 0, 0, 0, 0, *field, 0, NULL);
        for(playit = player.begin(); playit != player.end(); playit++) {
            float bgrndX = getRelativePositionX(*((*playit)->getSpacecraft()), bgrndUpperLeft);
            float bgrndY = getRelativePositionY(*((*playit)->getSpacecraft()), bgrndUpperLeft);
            if (!dynamic_cast<HumanNetworkPlayer*>(*playit)) {
                emit lifepoints((*playit)->getHealthPercentage());
                emit backgroundPos(bgrndX, bgrndY, field->getWidth(), field->getHeight());
                emit renderObject(viewlist);
                emit activeWeaponGame((*playit)->getWeapon());
            } else {
                serializedViewlist += "clifepoints:" +
                                      QString::number((*playit)->getHealthPercentage()) + "\n";
                serializedViewlist += "cweapon:" +
                                      QString::number((*playit)->getWeapon()) + "\n";
                serializedViewlist += "cbackgroundPos:" + QString::number(bgrndX) +
                                        ":" + QString::number(bgrndY) +
                                        ":" + QString::number(field->getWidth()) +
                                        ":" + QString::number(field->getHeight()) +
                                        "\n";
                emit sendViewlist(serializedViewlist);
            }
        }
    } else {
        stop();
    }
}

float GameLoop::getRelativePositionX(Spacecraft &anchor, GameActor &other) const
{
    return anchor.getPosition()[0] - other.getPosition()[0];
}

float GameLoop::getRelativePositionY(Spacecraft &anchor, GameActor  &other) const
{
    return anchor.getPosition()[1] - other.getPosition()[1];
}


