#include "Rectangles.h"

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
    if (Width <= 0) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Width." << std::endl; error = true; currentY++;}
    else if (Height <= 0) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Height." << std::endl; error = true; currentY++;}
    else if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol" << std::endl; error = true; currentY++;}
    else  error = false;
}

void Rectangles::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Width: " << Width << std::endl;
    std::cout << "Height: " << Height << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
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
