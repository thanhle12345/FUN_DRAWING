/*
        Rectangles Data format:
            Type: Triangle
            TriangleType: "IsoscelesTriangle" or "RightTriangle"
            Width: between 10 and 50.
            Height: between 10 and 50.
            DrawSymbol: a character.

        Example:
            [Object6]
            Type = Triangle
            TriangleType = IsoscelesTriangle
            Width = 31
            Height = 20
            DrawSymbol = +
*/

#include "Triangles.h"

const std::string Attribute[4] = {"TriangleType","Width","Height","DrawSymbol"};

Triangles::Triangles(){}

void Triangles::SetWidth(int w){Width = w;}
void Triangles::SetHeight(int h){Height = h;}
int Triangles::GetWidth(){return Width;}
int Triangles::GetHeight(){return Height;}

void Triangles::GetData(std::string attr, std::string value)
{
    if (attr == "TriangleType") TriangleType = value;
    else if (attr == "Width") Width = std::stoi(value);
    else if (attr == "Height") Height = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Triangles::CheckingError()
{
    if (TriangleType != "IsoscelesTriangle" && TriangleType != "RightTriangle") {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Triangle Type. Triangle Type can be RightTriangle or IsoscelesTriangle" << std::endl; error = true; currentY++;}
    if (Width < 10 || Width > 50) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Width. Width between 10 and 50." << std::endl;  error = true; currentY++;}
    if (Height < 10 || Height > 50) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Height. Height between and to 50." << std::endl; error = true; currentY++;}
    if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol. No DrawSymbol." << std::endl; error = true; currentY++;}
}

void Triangles::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "TriangleType: " << TriangleType << std::endl;
    std::cout << "Width: " << Width << std::endl;
    std::cout << "Height: " << Height << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol  << "\n" << std::endl;
    currentY += 7;
}

void Triangles::Draw()
{
    if(error == false){
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
}

bool Triangles::CheckAttribute(std::string attr)
{
    for (auto i:Attribute)
    {
        if (attr == i) return true;
    } return false;
}
