#ifndef GRAVITRONDIFFICULTIES_H
#define GRAVITRONDIFFICULTIES_H

#include <QObject>

class GravitronDifficulties : public QObject
{
    Q_OBJECT

    public:
        enum EnumDifficulies
        {
            EASY, MIDDLE, HARD
        };
        Q_ENUMS(EnumDifficulies)

        //std::string GravitronDifficultiesNames[3] =  {"easy","middle","hard"};
};
#endif // GRAVITRONDIFFICULTYS_H
