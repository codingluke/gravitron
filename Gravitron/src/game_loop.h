#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <QThread>

class GameLoop : public QThread
{
    Q_OBJECT

    private:
        bool running;

    public:
        void run();
        void stop();

    private:
        void processInput();
        void update();
        void render();
        double getCurrentTime();

    signals:
        void my_signal();
};

#endif
