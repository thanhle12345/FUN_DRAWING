#include <iostream>
#include <UIHandler.h>
#include <InputHandler.h>
#include <windows.h>

/*      Find and see data inside below file to know data structure of the object.
            D:\HVN\TRAINING_EXERCISES\Example1.txt : Has no Error.
            D:\HVN\TRAINING_EXERCISES\Example2.txt : Has Error between TD-005 to TD-049
            D:\HVN\TRAINING_EXERCISES\Example3.txt : Data structure in file with ini format
        Text format are ini format as example above. Multiple object are possible.
        Object can be Rectangles, Triangles, Ellipses, Lines.
        currentY is current position displaying next information.
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
            IH.Readfile();
            UI.setkey = 0;
            break;
        }
    } while (UI.setkey != 3);
    return 0;
}
