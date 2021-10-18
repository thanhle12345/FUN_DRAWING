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
        int Number {0};
        char DrawSymBol {0};
        bool error {false};

    public:
        Objects();

        void SetName(std::string str);
        void SetType(std::string str);
        void SetNumber(int num);

        std::string GetName();
        std::string GetType();
        int GetNumber();

        virtual void GetData(std::string attr, std::string value);
        void CheckingObject();
        virtual void CheckingError();
        virtual void Draw();
        virtual void DataInfo();
        bool CheckObject(std::string type);
        virtual bool CheckAttribute(std::string attr);
};

#endif // OBJECTS_H
