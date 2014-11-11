#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>
#include <string>

using namespace std;

class GameLoop : public QObject
{
    Q_OBJECT
    QThread workerThread;

    private:
        bool running;
        double ms_per_update;

    public slots:
        void doWork();
        void stop();

    private:
        void processInput();
        void update();
        void render();
        double getCurrentTime();

    signals:
        void ping(const string &result);
};

#endif