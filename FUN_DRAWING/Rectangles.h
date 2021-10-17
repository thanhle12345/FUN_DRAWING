#ifndef RECTANGLES_H
#define RECTANGLES_H
/*
        Rectangles Data format:
            Type: Rectangle
            Width: a number > 0.
            Height: a number > 0.
            DrawSymbol: a character.

        Example:
            [Object1]
            Type = Rectangle
            Width = 50
            Height = 30
            DrawSymbol = *
*/

#include <Objects.h>

class Rectangles: public Objects
{
private:
    int Width {0};
    int Height {0};
public:
    Rectangles();
    std::string Attribute[3] = {"Width","Height","DrawSymbol"};
    void SetWidth(int w);
    void SetHeight(int h);
    int GetWidth();
    int GetHeight();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
};
#endif // RECTANGLES_H
