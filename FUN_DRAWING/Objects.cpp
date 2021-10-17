#include "Objects.h"

HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
COORD destCoord;
int currentY = 0;
const std::string ObjectType[4] = {"Rectangle","Triangle","Ellipse","Line"};

Objects::Objects(){}

bool Objects::CheckObject(std::string type)
{
    for(auto i : ObjectType)
    {
        if (type == i) return true;
    }
    return false;
}

void Objects::SetName(std::string str){Name = str;}
void Objects::SetType(std::string str){Type = str;}

std::string Objects::GetName(){return Name;}
std::string Objects::GetType(){return Type;}
char Objects::GetSym(){};

bool Objects::CheckAttribute(std::string attr){}
bool Objects::CheckingError(std::string attr, std::string value){}
bool Objects::CheckFinish(){}
void Objects::GetData(std::string attr, std::string value){}
//void Objects::ShowError(){}
void Objects::Draw(){}
void Objects::DataInfo(){}
