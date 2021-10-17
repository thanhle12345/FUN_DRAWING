#ifndef OBJECTS_H
#define OBJECTS_H
#include <windows.h>
#include <iostream>

extern HANDLE hStdout;
extern COORD destCoord;
extern int currentY;

class Objects
{
    protected:
        std::string Name {0};
        std::string Type {0};
        char DrawSymBol {0};
    public:
        Objects();
        void SetName(std::string str);
        void SetType(std::string str);

        std::string GetName();
        std::string GetType();
        virtual char GetSym();

        bool CheckObject(std::string type);
        virtual bool CheckAttribute(std::string attr);
        virtual bool CheckingError(std::string attr, std::string value);
        virtual void GetData(std::string attr, std::string value);
        virtual bool CheckFinish();
        virtual void Draw();
        virtual void DataInfo();
};

#endif // OBJECTS_H
