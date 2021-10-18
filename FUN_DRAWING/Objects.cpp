#include "Objects.h"

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;
int currentY = 0;
const std::string ObjectType[4] = {"Rectangle","Triangle","Ellipse","Line"};

Objects::Objects(){}

void Objects::CheckingObject()
{
    if (Name == "") {std::cout << "WARNING: Object " << Number << ": " << Name << " has no name." << std::endl; error = true; currentY++;}
    if (Type != "Rectangle" && Type != "Triangle" && Type != "Ellipse" && Type != "Line") {std::cout << "ERROR: Object " << Number << ": " << Name << " is wrong Type. Object Type can be Rectangle, Triangle, Ellipse or Line.\n" << std::endl; error = true; currentY+=4;}
}

void Objects::SetName(std::string str){Name = str;}
void Objects::SetType(std::string str){Type = str;}
void Objects::SetNumber(int num){Number = num;}

std::string Objects::GetName(){return Name;}
std::string Objects::GetType(){return Type;}
int Objects::GetNumber(){return Number;}

void Objects::GetData(std::string attr, std::string value){}
void Objects::CheckingError(){}
void Objects::Draw(){}
void Objects::DataInfo(){}
bool Objects::CheckAttribute(std::string attr){}

bool Objects::CheckObject(std::string type)
{
    for (auto i : ObjectType)
    {
        if (type == i) return true;
    }return false;
}
