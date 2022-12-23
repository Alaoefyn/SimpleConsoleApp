/*1-Introduction
-Affan Selim	
-KAYA
-200709006
-Computer Engineering (English)
-Object Oriented Programming--CEN-104-50-50
-2020/2021 2nd Somestr
-Project 2
-Asst.Prof.Ahmet COÞKUNÇAY */

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
