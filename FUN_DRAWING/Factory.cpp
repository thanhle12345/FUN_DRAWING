#include "Factory.h"

Factory::Factory(){}
std::vector<Objects*> Storage::ObjectList;

Objects* Factory::createObject(std::string type)
{
    if (type == "Rectangle") return new Rectangles;
    else if (type == "Triangle") return new Triangles;
    else if (type == "Ellipse") return new Ellipses;
    else if (type == "Line") return new Lines;
    else return new Objects;
}
void Storage::addObject(Objects *Object){ObjectList.push_back(Object);}
std::vector<Objects*> Storage::getObject(){return ObjectList;}
