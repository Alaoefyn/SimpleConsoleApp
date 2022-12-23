

#include <string>
#include "User_200709006.h"

bool User_200709006::LogIn(string &usr, string &password)
{
    if (usr==username && password==password)
    {
        return true;
    }
    else
    {
        return false;
    }
}
