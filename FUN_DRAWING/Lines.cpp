/*
        Lines Data format:
            Type: Line
            Length: between 10 and 100.
            Direction: "Vertical" or "Horizontal"
            DrawSymbol: a character.

        Example:
            [Object7]
            Type = Line
            Length = 50
            Direction = Vertical
            DrawSymbol = ~
*/

#include "Lines.h"

Lines::Lines(){}

void Lines::SetLength(int length){Length = length;}
void Lines::SetDir(std::string dir){Direction = dir;}
int Lines::GetLength(){return Length;}

std::string Lines::GetDir(){return Direction;}

void Lines::GetData(std::string attr, std::string value)
{
    if (attr == "Length") Length = std::stoi(value);
    else if (attr == "Direction") Direction = value;
    else if (attr == "DrawSymbol") DrawSymBol = value[0];
}

void Lines::CheckingError()
{
    if (Length < 10 || Length > 100) {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Length. Length between 10 and 100." << std::endl; error = true; currentY++;}
    if (Direction != "Vertical" && Direction != "Horizontal") {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid Direction. Direction can be Vertical or Horizontal" << std::endl; error = true; currentY++;}
    if (DrawSymBol == '\0') {std::cout << "ERROR: Object " << Number << ": " << Name << " Invalid DrawSymbol. No DrawSymbol." << std::endl; error = true; currentY++;}
}

void Lines::DataInfo()
{
    std::cout << "Object " << Number << " Infomation:" << std::endl;
    std::cout << "Name: " << Name << std::endl;
    std::cout << "Type: " << Type << std::endl;
    std::cout << "Length: " << Length << std::endl;
    std::cout << "Direction: " << Direction << std::endl;
    std::cout << "DrawSymbol: " << DrawSymBol << "\n" << std::endl;
    currentY += 6;
}

void Lines::Draw()
{
    if(error == false){
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
}

