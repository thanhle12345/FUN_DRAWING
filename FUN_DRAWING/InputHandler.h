#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <iostream>
#include <fstream>
#include <Factory.h>
#include <UIHandler.h>
#include <Objects.h>

extern int num_obj;
extern int error_key;
class InputHandler
{
private:
    std::string filepath;
    std::string name;
    std::string type;
//    std::string Type[4] = {"Rectangle","Triangle","Ellipse","Line"};
    Objects* object = NULL;
    std::vector<Objects*> objects;

public:
    InputHandler();
    void FileHandle();
    void GetData(std::string data);
};
#endif // INPUTHANDLER_H
