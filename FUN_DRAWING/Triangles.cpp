#include "Triangles.h"

Triangles::Triangles(){}

void Triangles::SetWidth(int w){Width = w;}
void Triangles::SetHeight(int h){Height = h;}
int Triangles::GetWidth(){return Width;}
int Triangles::GetHeight(){return Height;}
char Triangles::GetSym(){return DrawSymBol;}

bool Triangles::CheckFinish(){return ((TriangleType == "IsoscelesTriangle" || TriangleType == "RightTriangle") && Width > 0 && Height > 0 && DrawSymBol != '\0');}

bool Triangles::CheckAttribute(std::string attr)
{
    for (auto i : Attribute) {
        if (i == attr) return true;
    }
    return false;
}

bool Triangles::CheckingError(std::string attr, std::string value)
{
    if (attr == "Width") return (std::stoi(value) > 0);
    else if (attr == "Height") return (std::stoi(value) > 0);
    else if (attr == "TriangleType") return (value == "IsoscelesTriangle" || value == "RightTriangle");
    else if (attr == "DrawSymbol") return (value.length() == 1);
    else return false;
}

void Triangles::GetData(std::string attr, std::string value)
{
    if (attr == "TriangleType") TriangleType = value;
    else if (attr == "Width") Width = std::stoi(value);
    else if (attr == "Height") Height = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Triangles::DataInfo()
{
    std::cout << Name << ": " << Type << std::endl;
    std::cout << "TriangleType: " << TriangleType << std::endl;
    std::cout << "Width: " << Width << std::endl;
    std::cout << "Height: " << Height << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
    currentY += 5;
}

void Triangles::Draw()
{
//    std::cout << Name << " :" << std::endl;
    currentY++;
    int x,y;
    if (TriangleType == "IsoscelesTriangle"){
        for (x = (Width-1)/2; x <= (Width-1); x++){
                y = round(2*(Height-1-1)*x/(Width-1) + 2 - (Height-1));
                destCoord.X = x;
                destCoord.Y = y + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;

                destCoord.X = Width - 1 - x;
                destCoord.Y = y + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;
        }
        for (x = 0; x <= Width-1; x++){
            destCoord.X = x;
            destCoord.Y = Height-1 + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            std::cout << DrawSymBol;
        }
    }
    if (TriangleType == "RightTriangle"){
        for (y = 0; y <= Height-1; y++){
            destCoord.X = 0;
            destCoord.Y = y + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            std::cout << DrawSymBol;
        }
        for (x = 0; x <= Width-1; x++){
            if (x%2){
                y = round(x*(Height-1)/(Width-1)-1);
                destCoord.X = x;
                destCoord.Y = y + currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;
            }
        }
        for (x = 0; x <= Width-1; x++){
            destCoord.X = x;
            destCoord.Y = Height-1 + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            std::cout << DrawSymBol;
        }
    }
    currentY += Height + 1;
    destCoord.X = 0;
    destCoord.Y = currentY;
    SetConsoleCursorPosition(hStdout, destCoord);
}
