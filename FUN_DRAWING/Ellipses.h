#ifndef ELLIPSES_H
#define ELLIPSES_H

/*
        Ellipse Data format:
            Type: Ellipse
            BigAxis: a number > 0.
            SmallAxis: a number > 0.
            DrawSymbol: a character.

        Example:
            [Object3]
            Type = Ellipse
            BigAxis = 50
            SmallAxis = 30
            DrawSymbol = -
*/

#include <Objects.h>
#include <math.h>

class Ellipses: public Objects
{
private:
    int BigAxis {0};
    int SmallAxis {0};
public:
    Ellipses();
    std::string Attribute[3] = {"BigAxis","SmallAxis","DrawSymbol"};
    void SetBigAxis(int big);
    void SetSmallAxis(int small);
    int GetBigAxis();
    int GetSmallAxis();
    char GetSym();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
};

#endif // ELLIPSES_H
