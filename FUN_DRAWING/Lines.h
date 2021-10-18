#ifndef LINES_H
#define LINES_H


#include <Objects.h>

class Lines: public Objects
{
private:
    int Length {0};
    std::string Direction {0};
public:
    Lines();
    std::string Attribute[3] = {"Length","Direction","DrawSymbol"};
    void SetLength(int length);
    void SetDir(std::string dir);
    int GetLength();
    std::string GetDir();

    void GetData(std::string attr, std::string value);
    void CheckingError();
    void Draw();
    void DataInfo();
};

#endif // LINES_H
