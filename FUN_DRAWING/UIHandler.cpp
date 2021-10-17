#include "UIHandler.h"

UIHandler::UIHandler(){}

void UIHandler::Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void UIHandler::ShowOption()
{
    for (int i = 0;;){
        system("CLS");
        Color(Set[0]);
        std::cout << "1. Draw " << std::endl;
        Color(Set[1]);
        std::cout << "2. Open File " << std::endl;
        Color(Set[2]);
        std::cout << "0. Exit Program " << std::endl;

        key = _getch();

        if (key == 72 && (Counter >= 2 && Counter <= 3)) Counter--;
        if (key == 80 && (Counter >= 1 && Counter <= 2)) Counter++;

        if (Counter == 1) {Set[0] =12;Set[1] = 7; Set[2] = 7;}
        if (Counter == 2) {Set[1] =12;Set[0] = 7; Set[2] = 7;}
        if (Counter == 3) {Set[2] =12;Set[0] = 7; Set[1] = 7;}

        if (key == '\r' && Counter == 1) setkey = 1;
        if (key == '\r' && Counter == 2) setkey = 2;
        if (key == '\r' && Counter == 3) setkey = 3;

        if (key == '\r') break;
    }
}

void UIHandler::Draw()
{
    system("CLS");
    std::vector<Objects*> ListObjects = Storage::getObject();
//    for (int i = 1; i <= num_obj; i++)
//    {
//        switch (error_key) {

//        }
//    }
    for (auto i : ListObjects)
    {
//        std::cout << i->GetErrorKey() << std::endl;
        i->DataInfo();
        i->Draw();
    }
    char cont;
    std::cout << "\nDo you want to draw any shape else? [Y/N]: " ;
    std::cin >> cont;
    cont = toupper(cont);
    if (cont == 'Y') setkey = 0;
    else exit(0);
}
