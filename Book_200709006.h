/*1-Introduction
-Affan Selim	
-KAYA
-200709006
-Computer Engineering (English)
-Object Oriented Programming--CEN-104-50-50
-2020/2021 2nd Somestr
-Project 2
-Asst.Prof.Ahmet COÞKUNÇAY */

#ifndef BOOK_200709006_H
#define BOOK_200709006_H
//Adding our special maked libraries.

#include <string>

using namespace std;
//Definition for book functions.

class Book_200709006
{
public:
    void SetTitle(string);

    void SetAuthor(string);

    void SetPubDate(string);

    void SetStatus(string);

    void SetHolder(string);

    void UpdateId(int);
    //Special strings.

    string TakeCurrentSt();

    string GetTitle();

    string TakeAuthorsNm();

    string GetPubDate();

    string GetHolder();

    int GetBookId();

protected:
    string title;
    string author;
    string pubDate;

    string status;
    string holder;
    
    int bookIde;
};


#endif 
