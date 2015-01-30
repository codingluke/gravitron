#include "headers/GameField.h"

/**
 * The default constructor.
 */
GameField::GameField()
{
    width = 0;
    height = 0;
}

/**
 * The constructor. Instanciates a GameField with given dimensions.
 * @param width the width of the GameField 
 * @param height the height of the GameField
 */
GameField::GameField(int width, int height)
{
    this->width = width;
    this->height = height;
}

/**
 * Setter for the fields width.
 * @param width the width value to set
 */
void GameField::setWidth(int width)
{
    this->width = width;
}

/**
 * Setter for the fields height.
 * @param height the height value to set
 */
void GameField::setHeight(int height)
{
    this->height = height;
}

/**
 * Getter for the fields height.        
 * @return the current height
 */
int GameField::getHeight() const
{
    return height;
}

/**
 * Getter for the fields width.
 * @return the current width
 */
int GameField::getWidth() const
{
    return width;
}
