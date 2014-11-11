#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <string>
#include "GameLoop.h"

using namespace std;

class Game: public QObject
{
    Q_OBJECT
    QThread workerThread;

    public:
        Game(QObject *parent = 0);
        ~Game();

    public slots:
        void handleResults(const string &result);

    signals:
        Q_INVOKABLE void start();
        Q_INVOKABLE void stop();

    private:
        void init();
};

#endif
