#ifndef GAMEFIELD_HEADER
#define GAMEFIELD_HEADER

/**
 * GameField represents the area in which the game plays out. 
 * More precisly, it defines the arenas dimensions.
 */
class GameField
{
private:
    int height;
    int width;

public:
    GameField();
    GameField(int, int);


    void setWidth(int);
    void setHeight(int);

    int getHeight() const;
    int getWidth() const;
};
#endif
