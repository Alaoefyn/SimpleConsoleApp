

#include <iostream>
#include "Book_200709006.h"

using namespace std;

void Book_200709006::SetTitle(string t)
{
    title = t;
}

void Book_200709006::SetAuthor(string a)
{
    author = a;
}

void Book_200709006::SetPubDate(string d)
{
    pubDate = d;
}

void Book_200709006::SetStatus(string s)
{
    if (s=="Hold" || s=="Unhold")
    {
        status = s;
    }
    //Outros for if book is given somone or not.If it is available the books status will be unhold,if it is not,then it will says hold.
    //A member cant borrow the holded book ,says pdf.
    else
    {
        cout << "\nStatus can only be 'Hold' or 'Unhold'" <<endl
             << "Setting it to 'Unhold'" << endl;
        status = "Unhold";
    }
    //If user give different status from hold or unhold,system will auto correct it to Unhold.
}

void Book_200709006::SetHolder(string s)
{
    holder = s;
}

string Book_200709006::TakeCurrentSt()
{
    return status;
}

string Book_200709006::GetTitle()
{
    return title;
}

string Book_200709006::TakeAuthorsNm()
{
    return author;
}

string Book_200709006::GetPubDate()
{
    return pubDate;
}

string Book_200709006::GetHolder()
{
    return holder;
}

void Book_200709006::UpdateId(int n)
{
    bookIde = n;
}

int Book_200709006::GetBookId()
{
    return bookIde;
}
