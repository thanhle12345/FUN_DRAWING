#ifndef TRIANGLES_H
#define TRIANGLES_H
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
