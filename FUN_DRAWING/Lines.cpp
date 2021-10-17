#include "Lines.h"

Lines::Lines(){}

void Lines::SetLength(int length){Length = length;}
void Lines::SetDir(std::string dir){Direction = dir;}
int Lines::GetLength(){return Length;}
char Lines::GetSym(){return DrawSymBol;}
std::string Lines::GetDir(){return Direction;}

bool Lines::CheckFinish(){return (Length > 0 && (Direction == "Vertical"|| Direction == "Horizontal") && DrawSymBol != '\0');}

bool Lines::CheckAttribute(std::string attr)
{
    for (auto i : Attribute) {
        if (i == attr) return true;
    }
    return false;
}

bool Lines::CheckingError(std::string attr, std::string value)
{
    if (attr == "Length") return (std::stoi(value) > 0);
    else if (attr == "Direction") return (value == "Vertical" || value == "Horizontal");
    else if (attr == "DrawSymbol") return (value.length() == 1);
    else return false;
}

void Lines::GetData(std::string attr, std::string value)
{
    if (attr == "Length") Length = std::stoi(value);
    else if (attr == "Direction") Direction = value;
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Lines::DataInfo()
{
    std::cout << Name << ": " << Type << std::endl;
    std::cout << "Length: " << Length << std::endl;
    std::cout << "Direction: " << Direction << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << std::endl;
    currentY += 4;
}

void Lines::Draw()
{
//    std::cout << Name << " :" << std::endl;
    currentY++;
    if (Direction == "Vertical"){
        for (int i = 0; i <= Length-1; i++){
                destCoord.X = i;
                destCoord.Y = currentY;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;
        }
        currentY += 1;
        destCoord.X = 0;
        destCoord.Y = currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
    }
    else if (Direction == "Horizontal"){
        for (int i = 0; i <= Length-1; i++){
                destCoord.X = 0;
                destCoord.Y = currentY + i;
                SetConsoleCursorPosition(hStdout, destCoord);
                std::cout << DrawSymBol;
        }
        currentY += Length + 1;
        destCoord.X = 0;
        destCoord.Y = currentY;
        SetConsoleCursorPosition(hStdout, destCoord);
    }
}

