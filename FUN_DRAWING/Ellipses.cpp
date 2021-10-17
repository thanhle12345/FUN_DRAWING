#include "Ellipses.h"

Ellipses::Ellipses(){}

void Ellipses::SetBigAxis(int big){BigAxis = big;}
void Ellipses::SetSmallAxis(int small){SmallAxis = small;}
int Ellipses::GetBigAxis(){return BigAxis;}
int Ellipses::GetSmallAxis(){return SmallAxis;}

void Ellipses::GetData(std::string attr, std::string value)
{
    if (attr == "BigAxis") BigAxis = std::stoi(value);
    else if (attr == "SmallAxis") SmallAxis = std::stoi(value);
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Ellipses::CheckingError()
{
    if (BigAxis <= 0) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid BigAxis" << std::endl; error = true; currentY++;}
    else if (SmallAxis <= 0) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid SmallAxis" << std::endl; error = true; currentY++;}
    else if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol" << std::endl; error = true; currentY++;}
    else error = false;
}

void Ellipses::Draw()
{
    if(error == false){
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
}

void Ellipses::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "BigAxis: " << BigAxis << std::endl;
    std::cout << "SmallAxis: " << SmallAxis << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
    currentY += 6;
}
