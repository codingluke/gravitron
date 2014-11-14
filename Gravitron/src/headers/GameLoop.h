#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <string>
#include <QQmlApplicationEngine>

using namespace std;

class GameLoop : public QObject
{
    Q_OBJECT
    QThread workerThread;

    private:
        bool running;
        int ms_per_update;

    public slots:
        void run();
        void stop();

    private:
        void processInput();
        void update();
        void render();

    signals:
        void ping(const string &result);
};

#endif
