#ifndef FACTORY_H
#define FACTORY_H
#include <vector>
#include <Objects.h>
#include <Rectangles.h>
#include <Triangles.h>
#include <Ellipses.h>
#include <Lines.h>
class Factory
{
public:
    Factory();
    static Objects* createObject(std::string type);
};

class Storage
{
private:
    static std::vector<Objects*> ObjectList;
public:
    static void addObject(Objects* Object);
    static std::vector<Objects*> getObject();
};
#endif // FACTORY_H
