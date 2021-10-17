#ifndef ELLIPSES_H
#define ELLIPSES_H

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
    bool CheckAttribute(std::string attr);
    bool CheckingError(std::string attr, std::string value);
    void GetData(std::string attr, std::string value);
    bool CheckFinish();
    void Draw();
    void DataInfo();
};

#endif // ELLIPSES_H
