#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <fstream>
#include <Factory.h>
#include <UIHandler.h>
#include <Objects.h>

class InputHandler
{
private:
    std::string filepath;
    std::string name;
    std::string type;
    Objects* object = NULL;
    std::vector<Objects*> objects;

public:
    bool END_OBJ = false;
    InputHandler();
    void Readfile();
    void GetData(std::string data);
};
#endif // INPUTHANDLER_H
