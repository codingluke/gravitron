#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <string>
#include <QString>
#include <QQmlApplicationEngine>
#include "GameActor.h"
#include "GameActorView.h"
#include <QKeyEvent>

using namespace std;

//class GameLoop : public QObject
class GameLoop : public QThread
{
    Q_OBJECT

    private:
        bool running;
        int ms_per_update;
        QObject *game;
        QQmlApplicationEngine *engine;
        vector<GameActor> actors;
        int inputs;

    protected:
        bool eventFilter(QObject *obj, QEvent *event);

    public:
        GameLoop();

    public slots:
        void run();
        void stop();
        void inputEvents(int code);

    private:
        void processInput();
        void update();
        void render();
        void applyGravitationToAllActor();

    signals:
        void ping(const string &result);
        void renderObject(vector<GameActorView*> *views);
};

#endif
