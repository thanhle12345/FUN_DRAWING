#ifndef ELLIPSES_H
#define ELLIPSES_H

#include <Objects.h>
#include <math.h>

class Ellipses: public Objects
{
private:
    int HorizontalAxis {0};
    int VerticalAxis {0};
public:
    Ellipses();
    void SetHorizontalAxis(int big);
    void SetVerticalAxis(int small);
    int GetHorizontalAxis();
    int GetVerticalAxis();
    char GetSym();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
    bool CheckAttribute(std::string attr);
};

#endif // ELLIPSES_H
