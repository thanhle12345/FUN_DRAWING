/*
        Rectangles Data format:
            Type: Rectangle
            Width: between 10 and 50.
            Height: between 10 and 50.
            DrawSymbol: a character.

        Example:
            [Object1]
            Type = Rectangle
            Width = 50
            Height = 30
            DrawSymbol = *
*/

#include "Rectangles.h"

const std::string Attribute[3] = {"Width","Height","DrawSymbol"};

Rectangles::Rectangles(){}

void Rectangles::SetWidth(int w){Width = w;}
void Rectangles::SetHeight(int h){Height = h;}
int Rectangles::GetWidth(){return Width;}
int Rectangles::GetHeight(){return Height;}

void Rectangles::GetData(std::string attr, std::string value)
{
    if (attr == "Width") Width = std::stoi(value);
    else if (attr == "Height") Height = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Rectangles::CheckingError()
{
    if (Width < 10 || Width > 50) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Width. Width between 10 and 50." << std::endl; error = true; currentY++;}
    if (Height < 10 || Height > 50) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Height. Height between 10 and 50." << std::endl; error = true; currentY++;}
    if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol. No DrawSymbol." << std::endl; error = true; currentY++;}
}

void Rectangles::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Width: " << Width << std::endl;
    std::cout << "Height: " << Height << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << "\n" << std::endl;
    currentY += 6;
}

void Rectangles::Draw()
{
    if(error == false){
        currentY++;
        int x,y;
        for (x = 0; x <= Width-1; x++){
            for (y = 0; y <= Height-1; y++){
                destCoord.X = x;
                destCoord.Y = currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;

                destCoord.X = 0;
                destCoord.Y = y + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;

                destCoord.X = Width - 1;
                destCoord.Y = y + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;

                destCoord.X = x;
                destCoord.Y = Height - 1 + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;
            }
        }
        currentY += Height + 1;
        destCoord.X = 0;
        destCoord.Y = currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
    }
}

bool Rectangles::CheckAttribute(std::string attr)
{
    for (auto i:Attribute)
    {
        if (attr == i) return true;
    } return false;
}
