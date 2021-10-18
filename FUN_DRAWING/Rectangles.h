#ifndef RECTANGLES_H
#define RECTANGLES_H
#include <Objects.h>

class Rectangles: public Objects
{
private:
    int Width {0};
    int Height {0};
public:
    Rectangles();
    void SetWidth(int w);
    void SetHeight(int h);
    int GetWidth();
    int GetHeight();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
    bool CheckAttribute(std::string attr);
};
#endif // RECTANGLES_H
