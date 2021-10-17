#include <iostream>
#include <UIHandler.h>
#include <InputHandler.h>
#include <windows.h>

/*      D:\HVN\TRAINING_EXERCISES\Example1.txt : no error
        D:\HVN\TRAINING_EXERCISES\Example2.txt : error
*/

int main()
{
    UIHandler UI;
    InputHandler IH;
    do {
        switch (UI.setkey) {
        case 0:
            UI.ShowOption();
            break;
        case 1:
            UI.Draw();
            break;
        case 2:
            IH.FileHandle();
            UI.setkey = 0;
            break;
        }
    } while (UI.setkey != 3);
    return 0;
}
