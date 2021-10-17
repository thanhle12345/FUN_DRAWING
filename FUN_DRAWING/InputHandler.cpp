#include "InputHandler.h"

/*
        errorkey = 0: Object has no error.
        errorkey = 1: Object has no name.
        errorkey = 2: Object Type is incorrect.
        errorkey = 3: Object Attribute is wrong format.
        errorkey = 4: Object Data is incorrect.
*/

int num_obj;
int error_key;

InputHandler::InputHandler(){}

void InputHandler::FileHandle()
{
    std::cout << "Include File Path: ";
    std::getline(std::cin, filepath);
    std::cout << std::endl;

    bool fileerror = true;
    do{
        std::string inputline;
        std::ifstream myfile(filepath);
        if (myfile.is_open()){
            while(std::getline(myfile,inputline)){
                GetData(inputline);
            }
//            for (auto i : objects){Storage::addObject(i);}
            myfile.close();
            fileerror = false;
        }
        else {
            std::cout << "ERROR: File not exist." << std::endl;
            std::cout << "Do you want to Exit? [Y/N]" << std::endl;

            char changefile;
            std::cin >> changefile;
            std::cout << std::endl;
            changefile = toupper(changefile);

            if (changefile == 'Y'){
                exit(0);
            }
            else if (changefile == 'N'){
                std::cout << "Include file path: ";
                std::getline(std::cin, filepath);
                std::getline(std::cin, filepath);
                std::cout << std::endl;
                fileerror = true;
            }
        }
    }while(fileerror);
}

void InputHandler::GetData(std::string data)
{
    if(data[0] == '[')
    {
        name = data.substr(1, data.length() - 2);
        num_obj++;
    }
    else {
        std::string delimiter = "=";
        size_t pos = 0;
        std::string key;
        std::string value;
        pos = data.find(delimiter);
        key = data.substr(0, pos - 1);
        value = data.substr(pos + 1 + delimiter.length(), data.length());
        if (key == "Type"){
            /*if (name =="") std::cout << "Object " << num << " has no name." << std::endl;
            else*/ if(object->CheckObject(value)){
                object = Factory::createObject(value);
                type = value;
                object->SetName(name);
                object->SetType(type);
            }/*else std::cout <<"error type" << std::endl;*/
        }
        else{
            if(object->CheckAttribute(key)){
                if(object->CheckingError(key, value)){
                    object->GetData(key, value);
                    if (object->CheckFinish()){
//                        objects.push_back(object);
                        Storage::addObject(object);
                        name.clear();
                        type.clear();
                        key.clear();
                        value.clear();
                        object = NULL;
                    }
                }/*else std::cout <<"error value" << std::endl;*/
            }/*else std::cout <<"error attribute" << std::endl;*/
        }
    }
}
