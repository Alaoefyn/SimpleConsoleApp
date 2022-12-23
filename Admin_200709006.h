/*1-Introduction
-Affan Selim	
-KAYA
-200709006
-Computer Engineering (English)
-Object Oriented Programming--CEN-104-50-50
-2020/2021 2nd Somestr
-Project 2
-Asst.Prof.Ahmet COÞKUNÇAY */

#ifndef ADMIN_200709006_H
#define ADMIN_200709006_H

#include "Book_200709006.h"
#include "Member_200709006.h"
#include "User_200709006.h"

//Admin options and operators.
class Admin_200709006 : public User_200709006
{
public:
    void AddUser(Member_200709006[], int);
    void AddBook(Book_200709006[], int);

    void ListUsers(Member_200709006[], int);
    void BooksList(Book_200709006[], int);
    
    void DeleteUser(Member_200709006[], int);
    void DeleteBook(Book_200709006[], int);
    
    void UsernameAs(string);
    void PasswordAs(string);
private:

    template<typename T>
    void DeleteItemFromArray(T arr, int aWidth, int ind);
};


#endif 
