#include "headers/GameLoop.h"
#include "headers/Spacecraft.h"
#include "headers/HumanNetworkPlayer.h"
#include <QTime>

using namespace std;

/**
 * Constructor of the GameLoop. Generates the beginning state of the
 * game through the GameGenerator.
 *
 * @param gGenerator GameGenerator setting up the beginning state of the game.
 */
GameLoop::GameLoop(GameGenerator gGenerator)
{
    gGenerator.generateGame(this);
}

/**
 * Deconstructor. Deletes all GameActors and Players.
 */
GameLoop::~GameLoop() {
    deleteActors();
    deletePlayers();
    deleteBots();
}

/**
 * Deletes all the GameActors.
 */
void GameLoop::deleteActors() {
    vector<GameActor*>::iterator it;
    for (it = actors.begin(); it < actors.end(); it++) {
        delete (*it);
    }
}

/**
 * Deletes all the Bots.
 */
void GameLoop::deleteBots() {
    vector<AIPlayer*>::iterator it;
    for (it = bots.begin(); it < bots.end(); it++) {
        delete (*it);
    }
}

/**
 * Deletes all the Players.
 */
void GameLoop::deletePlayers() {
    vector<Player*>::iterator it;
    for (it = players.begin(); it < players.end(); it++) {
        delete (*it);
    }
}

/**
 * Setting a new List of Bots.
 */
void GameLoop::setBots(vector<AIPlayer*> bots) {
    deleteBots();
    for (AIPlayer* kp : bots) {
        this->bots.push_back(kp);
    }
}

/**
 * Setting a new List of Players.
 */
void GameLoop::setPlayers(vector<Player*> players) {
    deletePlayers();
    this->players = players;
}

/**
 * Setting a new List of GameActor's
 */
void GameLoop::setActors(vector<GameActor*> actors) {
    deleteActors();
    this->actors = actors;
    remapActorsReferences();
}

/**
 * Gives all the Actors a reference to the actors list. So every actor
 * can update/manipulate the list.
 */
void GameLoop::remapActorsReferences()
{
    vector<GameActor*>::iterator it;
    for(it = actors.begin(); it != actors.end(); it++) {
        (*it)->setActors(&actors);
    }
}

/**
 * Setting a new GameField.
 */
void GameLoop::setGameField(GameField* newField)
{
    if (this->field)
        delete field;
    this->field = newField;
}

/**
 * The actual GameLoop. The run method is running inside a thread. In every
 * loop it processes the Input from the User/Network, updates all the GameActors,
 * renders the GameActors (by sending over Network or Signal). And checks if there is
 * a winner.
 */
void GameLoop::run()
{
    int lag = 0;
    int msLoopDuration = 30;
    running = true;
    QTime t;
    t.start();
    while (running)
    {
        t.restart();
        processInput();
        update();
        render();
        lag = msLoopDuration - t.elapsed();
        if (lag > 0) {
            QThread::msleep(lag);
        }
        checkWinner();
    }
}


/**
 * Sets the field running to flase, so the running thread gets stopped.
 */
void GameLoop::stop()
{
    running = false;
}

/**
 * Goes through the palyer list and the bots list, and checks if someone has won.
 * If there is a winner, the winner is send over Network and the game is stopped.
 */
void GameLoop::checkWinner()
{
    for (Player* p : players) {
        if (p->isWinner()) {
            emit theWinnerIs("The Winner is " + p->getPlayerName());
            emit sendViewlist("cwinner:The Winner Is " + p->getPlayerName() + "\n");
            QThread::msleep(10);
            stop();
        }
    }
    for (Player* p : bots) {
        if (p->isWinner()) {
            emit theWinnerIs("The Winner is " + p->getPlayerName());
            emit sendViewlist("cwinner:The Winner Is " + p->getPlayerName() + "\n");
            QThread::msleep(10);
            stop();
        }
    }
}

/**
 * Goes through all player and delegates processInput.
 */
void GameLoop::processInput()
{
    vector<Player*>::iterator it;
    for(it = players.begin(); it != players.end(); it++) {
      (*it)->processInput();
    }
}

/**
 * Goes through all GameActors and delegates the update method.
 * Deletes all the actors unless spacecrafts, when they are killed.
 * Delegates the update method to the bots.
 */
void GameLoop::update()
{
    for(unsigned int i = 0; i < actors.size(); i++) {
        actors[i]->updateAll();
    }
    for (unsigned int i = 0; i < actors.size(); i++)
    {
        Spacecraft* isSpacecraft = NULL;
        isSpacecraft = dynamic_cast<Spacecraft*>(actors[i]);
        if((actors[i]->isKilled()) && (!isSpacecraft)) {
            delete (actors[i]);
            actors.erase(actors.begin() + i);
        }
    }
    actors.shrink_to_fit();
    for (unsigned int i = 0; i < bots.size(); i++){
        bots[i]->update();
    }
}

/**
 * The render method getts all the GameActorVies form all the actors and sends them
 * through singlas or serialized through the network to the Game instance,
 * which will render the views.
 * It also recalculates the Positions of the gameactors according the players Spacecraft.
 * This has to be done twice, once for the local player and once for the Network player.
 * It also sends commands to the Game, such as lifepoints, player name, winner.
 *
 * IT SHOULD BE REFACTORED!
 */
void GameLoop::render()
{
    if(actors.size() > 0) { //wenn actors leer sind > speicherzugriffsfehler im vector
        vector<GameActorView*> *viewlist = new vector<GameActorView*>;
        vector<GameActor*>::iterator it;
        QString serializedViewlist("v");
        for(it = actors.begin(); it != actors.end(); it++) {
            GameActorView *view = (*it)->getView();
            if (players.size() == 2)
            {
                view->setProperty("x", getRelativePositionX(*(players[1]->getSpacecraft()), **it));
                view->setProperty("y", getRelativePositionY(*(players[1]->getSpacecraft()), **it));
                serializedViewlist += QString::fromStdString(view->toString());
                serializedViewlist += ";";
            }
                view->setProperty("x", getRelativePositionX(*(players[0]->getSpacecraft()), **it));
                view->setProperty("y", getRelativePositionY(*(players[0]->getSpacecraft()), **it));
                viewlist->push_back(view);
        }
        serializedViewlist += "\n";
        vector<Player*>::iterator playit;
        GameActor bgrndUpperLeft = GameActor(Vec3f(0, 0, 0), 0, 0, 0, 0, *field, 0, NULL);
        for(playit = players.begin(); playit != players.end(); playit++) {
            float bgrndX = getRelativePositionX(*((*playit)->getSpacecraft()), bgrndUpperLeft);
            float bgrndY = getRelativePositionY(*((*playit)->getSpacecraft()), bgrndUpperLeft);
            if (!dynamic_cast<HumanNetworkPlayer*>(*playit)) {
                emit lifepoints((*playit)->getHealthPercentage());
                emit backgroundPos(bgrndX, bgrndY, field->getWidth(), field->getHeight());
                emit renderObject(viewlist);
                emit activeWeaponGame((*playit)->getWeapon());
                emit fragStatus((*playit)->getFrag(), (*playit)->getKillPoints());
            } else {
                serializedViewlist += "clifepoints:" +
                                      QString::number((*playit)->getHealthPercentage()) + "\n";
                serializedViewlist += "cweapon:" +
                                      QString::number((*playit)->getWeapon()) + "\n";
                serializedViewlist += "cfrag:" +
                                      QString::number((*playit)->getFrag()) + "," +
                                      QString::number((*playit)->getKillPoints()) +
                                      "\n";
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

/**
 * Calculates the relative X position of all the actors to a given actor.
 *
 * @param anchor  Actor for the relative positions
 * @param other   Actor to be recalculated.
 *
 * @return new X value for the other actor.
 */
float GameLoop::getRelativePositionX(Spacecraft &anchor, GameActor &other) const
{
    return anchor.getPosition()[0] - other.getPosition()[0];
}

/**
 * Calculates the relative Y position of all the actors to a given actor.
 *
 * @param anchor  Actor for the relative positions
 * @param other   Actor to be recalculated.
 *
 * @return new Y value for the other actor.
 */
float GameLoop::getRelativePositionY(Spacecraft &anchor, GameActor  &other) const
{
    return anchor.getPosition()[1] - other.getPosition()[1];
}

