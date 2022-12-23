

#ifndef MEMBER_200709006_H
#define MEMBER_200709006_H

#include <iostream>
#include <iomanip>
#include "Member_200709006.h"
#include "Book_200709006.h"
#include "User_200709006.h"
//Adding our special maked libraries.

using namespace std;

class Member_200709006 : public User_200709006
{
public:
    //Functions used for Member.
    void TakeTheBook(string, Member_200709006[], Book_200709006[], int);

    void GivingBackTheBook(string, Member_200709006[], Book_200709006[], int);

    void BooksList(Book_200709006[], int);

    void PassContConfiguration(string, Member_200709006[], int);

    void TypedBookFound(Book_200709006[], int);

    void GiveName(string); 

    void UsernameAs(string);

    void MakeExistingBooksRes();

    void RefreshExistingBooks(int);

    void PasswordAs(string);

    void UpdateId(int);

    string TaknUsername();

    string GetName();

    string MembershipType();

    int BringCurrBook();

    void MembershipTypeAssign(string &);

    int GetMemberId();

private:
    string membershipType;
    int exstBook;
    int memberId;
};


#endif 
