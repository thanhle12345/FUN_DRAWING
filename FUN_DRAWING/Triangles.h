#ifndef TRIANGLES_H
#define TRIANGLES_H
/*
        Rectangles Data format:
            Type: Triangle
            TriangleType: "IsoscelesTriangle" or "RightTriangle"
            Width: a number > 0.
            Height: a number > 0.
            DrawSymbol: a character.

        Example:
            [Object6]
            Type = Triangle
            TriangleType = IsoscelesTriangle
            Width = 31
            Height = 20
            DrawSymbol = +
*/

#include "Objects.h"
#include <math.h>

class Triangles: public Objects
{
private:
    int Width {0};
    int Height {0};
    std::string TriangleType {0};
public:
    Triangles();
    std::string Attribute[4] = {"TriangleType","Width","Height","DrawSymbol"};
    void SetWidth(int w);
    void SetHeight(int h);
    int GetWidth();
    int GetHeight();
    std::string GetTriangleType();
    char GetSym();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
};
#endif // TRIANGLES_H
