#include "Ellipses.h"

Ellipses::Ellipses(){}

void Ellipses::SetBigAxis(int big){BigAxis = big;}
void Ellipses::SetSmallAxis(int small){SmallAxis = small;}
int Ellipses::GetBigAxis(){return BigAxis;}
int Ellipses::GetSmallAxis(){return SmallAxis;}
char Ellipses::GetSym(){return DrawSymBol;}

bool Ellipses::CheckFinish(){return (BigAxis > 0 && SmallAxis > 0 && DrawSymBol != '\0');}

bool Ellipses::CheckAttribute(std::string attr)
{
    for (auto i : Attribute) {
        if (i == attr) return true;
    }
    return false;
}

bool Ellipses::CheckingError(std::string attr, std::string value)
{
    if (attr == "BigAxis") return (std::stoi(value) > 0);
    else if (attr == "SmallAxis") return (std::stoi(value) > 0);
    else if (attr == "DrawSymbol") return (value.length() == 1);
    else return false;
}

void Ellipses::GetData(std::string attr, std::string value)
{
    if (attr == "BigAxis") BigAxis = std::stoi(value);
    else if (attr == "SmallAxis") SmallAxis = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Ellipses::Draw()
{
//    std::cout << Name << " :" << std::endl;
    currentY++;
    int x,y;
    double x1;
    for (x = 0; x <= BigAxis-1; x++){
        x1 = x;
        y = round((SmallAxis-1)/2 - (SmallAxis-1)/2*sqrt(1-(2*x1/(BigAxis-1)-1)*(2*x1/(BigAxis-1)-1)));
        destCoord.X = x1;
        destCoord.Y = y + currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
        std::cout << DrawSymBol;
        y = round((SmallAxis-1)/2 + (SmallAxis-1)/2*sqrt(1-(2*x1/(BigAxis-1)-1)*(2*x1/(BigAxis-1)-1)));
        destCoord.X = x1;
        destCoord.Y = y + currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
        std::cout << DrawSymBol;
    }
    currentY += SmallAxis + 1;
    destCoord.X = 0;
    destCoord.Y = currentY;
    SetConsoleCursorPosition(hStdout, destCoord);
}

void Ellipses::DataInfo()
{
    std::cout << Name << ": " << Type << std::endl;
    std::cout << "BigAxis: " << BigAxis << std::endl;
    std::cout << "SmallAxis: " << SmallAxis << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
    currentY += 4;
}
