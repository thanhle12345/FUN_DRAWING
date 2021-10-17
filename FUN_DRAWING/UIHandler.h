#ifndef UIHANDLER_H
#define UIHANDLER_H
#include <string>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <Objects.h>
#include <Factory.h>
#include <InputHandler.h>

class UIHandler
{
public:
    UIHandler();

    int Set[3] = {7,7,7};
    int Counter = 1;
    char key;
    char display;
    int setkey = 0;

    void Color(int color);
    void ShowOption();
    void Draw();
};

#endif // UIHANDLER_H
