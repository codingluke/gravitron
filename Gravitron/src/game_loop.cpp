#include "game_loop.h"
#include <iostream>
#include <iomanip>
#include <QTime>

using namespace std;

GameLoop::GameLoop()
{
  running = false;
}

void GameLoop::run()
{
  double MS_PER_UPDATE = 60.0;
  running = true;
  double start = getCurrentTime();
  double previous = getCurrentTime();
  double lag = 0.0;

  while (running)
  {
    double current = getCurrentTime();

    if ((current - start) > 250)
      running = false;

    double elapsed = current - previous;
    previous = current;
    lag += elapsed;

    processInput();

    while (lag >= MS_PER_UPDATE)
    {
      update();
      lag -= MS_PER_UPDATE;
    }

    render();
  }
}

void GameLoop::stop()
{
  running = false;
}

void GameLoop::processInput()
{
  //cout << "processInput!";
}

void GameLoop::update()
{
  cout << "update!";
}

void GameLoop::render()
{
  //cout << "render!";
}

double GameLoop::getCurrentTime()
{
  return QTime::currentTime().msec();
}
