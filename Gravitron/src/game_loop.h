#ifndef GAME_LOOP_H
#define GAME_LOOP_H

class GameLoop
{
  private:
    bool running;

  public:
    GameLoop();

    void run();
    void stop();

  private:
    void processInput();
    void update();
    void render();
    double getCurrentTime();
};

#endif
