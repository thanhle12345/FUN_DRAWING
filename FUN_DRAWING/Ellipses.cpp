/*
        Ellipse Data format:
            Type: Ellipse
            HorizontalAxis: between 10 and 100.
            VerticalAxis: between 10 and 100.
            DrawSymbol: a character.

        Example:
            [Object3]
            Type = Ellipse
            HorizontalAxis = 50
            VerticalAxis = 30
            DrawSymbol = -
*/

#include "Ellipses.h"

Ellipses::Ellipses(){}

void Ellipses::SetHorizontalAxis(int big){HorizontalAxis = big;}
void Ellipses::SetVerticalAxis(int small){VerticalAxis = small;}
int Ellipses::GetHorizontalAxis(){return HorizontalAxis;}
int Ellipses::GetVerticalAxis(){return VerticalAxis;}

void Ellipses::GetData(std::string attr, std::string value)
{
    if (attr == "HorizontalAxis") HorizontalAxis = std::stoi(value);
    else if (attr == "VerticalAxis") VerticalAxis = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Ellipses::CheckingError()
{
    if (HorizontalAxis < 10 || HorizontalAxis > 100) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid HorizontalAxis. HorizontalAxis between 10 and 100." << std::endl; error = true; currentY++;}
    if (VerticalAxis < 10 || VerticalAxis > 100) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid VerticalAxis. VerticalAxis between 10 and 100." << std::endl; error = true; currentY++;}
    if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol. No DrawSymbol." << std::endl; error = true; currentY++;}
}

void Ellipses::Draw()
{
    if(error == false){
        currentY++;
        int x,y;
        double x1;
        for (x = 0; x <= HorizontalAxis-1; x++){
            x1 = x;
            y = round((VerticalAxis-1)/2 - (VerticalAxis-1)/2*sqrt(1-(2*x1/(HorizontalAxis-1)-1)*(2*x1/(HorizontalAxis-1)-1)));
            destCoord.X = x1;
            destCoord.Y = y + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            std::cout << DrawSymBol;
            y = round((VerticalAxis-1)/2 + (VerticalAxis-1)/2*sqrt(1-(2*x1/(HorizontalAxis-1)-1)*(2*x1/(HorizontalAxis-1)-1)));
            destCoord.X = x1;
            destCoord.Y = y + currentY;
            SetConsoleCursorPosition(hStdout, destCoord);
            std::cout << DrawSymBol;
        }
        currentY += VerticalAxis + 1;
        destCoord.X = 0;
        destCoord.Y = currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
    }
}

void Ellipses::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "HorizontalAxis: " << HorizontalAxis << std::endl;
    std::cout << "VerticalAxis: " << VerticalAxis << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << "\n" << std::endl;
    currentY += 6;
}
