#include "headers/GameField.h"


GameField::GameField()
{
    width = 0;
    height = 0;
}

GameField::GameField(int width, int height)
{
    this->width = width;
    this->height = height;
}

void GameField::setWidth(int width)
{
    this->width = width;
}

void GameField::setHeight(int height)
{
    this->height = height;
}

int GameField::getHeight() const
{
    return height;
}

int GameField::getWidth() const
{
    return width;
}
