#include "login.h"
#include "menu.h"

int main()
{
    if (login() == 1)
    {
        mainMenu();
    }

    return 0;
}