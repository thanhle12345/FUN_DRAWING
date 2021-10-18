#include "InputHandler.h"

/*

*/
static int num_obj;
bool line_error {false}, has_error {false};

InputHandler::InputHandler(){}

void InputHandler::Readfile()
{
    int num_line = 0;
//    bool line_error {false}, has_error {false};
    std::cout << "Include File Path: ";
    std::getline(std::cin, filepath);
    std::cout << std::endl;

    bool fileerror = true;
    do{
        std::string inputline;
        std::ifstream myfile(filepath);
        if (myfile.is_open()){
            while(std::getline(myfile,inputline)){
                num_line++;
                if (inputline[0] == '[' || (inputline.find('=') != std::string::npos)) {GetData(inputline); line_error = false;}
                else line_error = true;
                if (line_error) {
                    std::cout << "\nERROR: Line " << num_line << " is wrong format." << std::endl;
                    std::cout << "Error at Object " << num_obj << " name: " << name << std::endl;
                    currentY +=2;
                    has_error = true;
                }
            }
            myfile.close();
            while (has_error) {
                std::cout << "\nPress [Enter] to continue..." << std::endl;
                char cont;
                cont = _getch();
                if (cont == '\r'){
                   break;
                }
            }
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
        std::string attr, value;
        pos = data.find(delimiter);
        attr = data.substr(0, pos - 1);
        value = data.substr(pos + 1 + delimiter.length(), data.length());
        if (attr == "Type"){
            object = Factory::createObject(value);
            type = value;
            object->SetName(name);
            object->SetType(type);
            object->SetNumber(num_obj);
        }else{
            object->GetData(attr, value);
            if (object->CheckObject(type)){
                if (object->CheckAttribute(attr) == false){
                    std::cout << "\nWARNING: Object " << num_obj << " Type: " << type << " has strange attribute. This is " << attr << std::endl;
                    has_error = true;
                }
            }
        }
        if (attr == "DrawSymbol") Storage::addObject(object);
    }
}
