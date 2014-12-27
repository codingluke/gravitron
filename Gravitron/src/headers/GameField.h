#ifndef GAMEFIELD_HEADER
#define GAMEFIELD_HEADER

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
