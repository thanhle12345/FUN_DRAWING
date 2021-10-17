#include "Rectangles.h"

Rectangles::Rectangles(){}

void Rectangles::SetWidth(int w){Width = w;}
void Rectangles::SetHeight(int h){Height = h;}
int Rectangles::GetWidth(){return Width;}
int Rectangles::GetHeight(){return Height;}
char Rectangles::GetSym(){return DrawSymBol;}

bool Rectangles::CheckFinish(){return (Width > 0 && Height > 0 && DrawSymBol != '\0');}

bool Rectangles::CheckAttribute(std::string attr)
{
    for (auto i : Attribute) {
        if (i == attr) return true;
    }
    return false;
}

bool Rectangles::CheckingError(std::string attr, std::string value)
{
    if (attr == "Width") return (std::stoi(value) > 0);
    else if (attr == "Height") return (std::stoi(value) > 0);
    else if (attr == "DrawSymbol") return (value.length() == 1);
    else return false;
}

void Rectangles::GetData(std::string attr, std::string value)
{
    if (attr == "Width") Width = std::stoi(value);
    else if (attr == "Height") Height = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Rectangles::DataInfo()
{
    std::cout << Name << ": " << Type << std::endl;
    std::cout << "Width: " << Width << std::endl;
    std::cout << "Height: " << Height << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
    currentY += 4;
}

void Rectangles::Draw()
{
//    std::cout << Name << " :" << std::endl;
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
