/*1-Introduction
-Affan Selim	
-KAYA
-200709006
-Computer Engineering (English)
-Object Oriented Programming--CEN-104-50-50
-2020/2021 2nd Somestr
-Project 2
-Asst.Prof.Ahmet COÞKUNÇAY */

#include "Member_200709006.h"

void Member_200709006::TakeTheBook(string user, Member_200709006 users[], Book_200709006 books[], int aWidth)
{
    bool usrCanTake = true;
    int bookIde;
    int usrInd;

    for (int i=0; i<aWidth; i++)
    {
        if (users[i].TaknUsername()==user) usrInd=i;
    }

    int takenBook = users[usrInd].BringCurrBook();
//  
    string memberT= users[usrInd].MembershipType();

    // Maximum value must be determineted and must obey the pdf while giving choices to compiler.
    //For an example,if you type on membership something else than 3 types,program will turn it to Student.
    
    if ((memberT=="Personnel" && takenBook>=3)||
        (memberT=="Student"&&takenBook>=5)||
        (memberT=="FacultyMember" && takenBook>=10)){
        
        usrCanTake= false;
    } 

    cout << "Book Id: ";
    //Rules from pdf to take book from library.
    cin >> bookIde;
    if (usrCanTake)
    {
        if (books[bookIde].TakeCurrentSt()=="Unhold")
        {
            users[usrInd].RefreshExistingBooks(1);
            books[bookIde].SetStatus("Hold");
            books[bookIde].SetHolder(user);
            cout << "Book borrowed successfully.Please do not forget to return the borrowed book to library.Enjoy your reading!" << endl;
        }
        else if (books[bookIde].TakeCurrentSt()=="Hold")
        {
            cout << "Sorry!The book you want has already been borrowed by someone else.Please look for another book." << endl;
        }
        else if (books[bookIde].TakeCurrentSt().empty())
        {
            cout << "Sorry!We do not have such a book." << endl;
        }
    }
    else
    {
        cout << "Sorry! You cannot borrow that many books." << endl;
    }
}

void Member_200709006::GivingBackTheBook(string user, Member_200709006 users[], Book_200709006 books[], int aWidth)
{
    int bookIde;
    int usrInd;

    for (int i=0; i<aWidth; i++)
    {
        if (users[i].TaknUsername()==user) usrInd=i;
    }

    cout << "Book Id: ";
    cin >> bookIde;
    //Book-return section.If there is not such a book on system,program will out a error message.

    if (books[bookIde].TakeCurrentSt()=="Hold" && books[bookIde].GetHolder()==user)
    {
        users[usrInd].RefreshExistingBooks(-1);
        books[bookIde].SetStatus("Unhold");
        cout << "You successfully returned a book you borrowed before.Thank you for obeying the rules!" << endl;
    }
    else
    {
        cout << "Error.You can't return this book." << endl;
    }
}

void Member_200709006::BooksList(Book_200709006 books[], int aWidth)
{
    //Making the ID -Book Name -Author Name -Status outro just like on pdf.
    if (books[0].GetTitle().empty())
    {
        cout << "Error.There are no books for list." << endl;
    }
    else
    {
        cout << setw(15) << left << "ID";
        cout << setw(15) << left << "Book Name";
        cout << setw(15) << left << "Author Name";
        cout << setw(15) << left << "Pub. Date";
        cout << setw(15) << left << "Status" << endl;

        for (int i = 0; i < aWidth; i++)
        {
            if (!books[i].GetTitle().empty())
            {
                cout << setw(15) << left << books[i].GetBookId();
                cout << setw(15) << left << books[i].GetTitle();
                cout << setw(15) << left << books[i].TakeAuthorsNm();
                cout << setw(15) << left << books[i].GetPubDate();
                cout << setw(15) << left << books[i].TakeCurrentSt() << endl;
            }
        }
    }
}

void Member_200709006::PassContConfiguration(string user, Member_200709006 users[], int aWidth)
{
    int usrInd;
    string replacedNewPassword;
    for (int i=0; i<aWidth; i++)
    {
        if (users[i].TaknUsername()==user) usrInd=i;
    }
//Here making another password for user.On pdf,starter password for any member is 'tmp'.
    cout << "Please enter your new password: ";
    cin >> replacedNewPassword;

    users[usrInd].PasswordAs(replacedNewPassword);
    cout << "\nPassword changed successfully!." << endl;
}

void Member_200709006::TypedBookFound(Book_200709006 books[], int aWidth)
{
    //Making the outros for Book.
    Book_200709006 typedBookFound[aWidth];

    string titl;
    string desnAuthor;

    cout << "Please enter the book name: ";
    cin >> titl;
    cout << "Please enter the author's name: ";
    cin >> desnAuthor;


    for (int i=0; i<aWidth; i++)
    {
        if (books[i].GetTitle()==titl && desnAuthor=="*")
        {
            typedBookFound[i] = books[i];
        }
        else if (books[i].TakeAuthorsNm()==desnAuthor && titl=="*")
        {
            typedBookFound[i] = books[i];
        }
        else if (books[i].TakeAuthorsNm()==desnAuthor && books[i].GetTitle()==titl)
        {
            typedBookFound[i] = books[i];
        }
    }

    if (typedBookFound[0].GetTitle().empty())
    {
        cout << "Sorry! No books found by system." << endl;
    }
    else
    {
        cout << "The book you were looking for was found successfully. Book Info: " << endl;
        //Result outro for searched book by members.
        for (int i=0; i<aWidth;i++)
        {
            if (!typedBookFound[i].GetTitle().empty())
            {
                cout << typedBookFound[i].GetBookId() << "     "
                     << typedBookFound[i].TakeAuthorsNm() << "     "
                     << typedBookFound[i].GetTitle() << "    "
                     << typedBookFound[i].GetPubDate() << "    "
                     << typedBookFound[i].TakeCurrentSt() << endl;
            }
        }
    }
}

void Member_200709006::GiveName(string s)
{
    name = s;
}

void Member_200709006::UsernameAs(string s)
{
    username = s;
}

void Member_200709006::MakeExistingBooksRes()
{
    exstBook = 0;
}

void Member_200709006::RefreshExistingBooks(int n)
{
    exstBook += n;
}

void Member_200709006::PasswordAs(string s)
{
    password = s;
}

string Member_200709006::TaknUsername()
{
    return username;
}

string Member_200709006::GetName()
{
    return name;
}

string Member_200709006::MembershipType()
{
    return membershipType;
}

int Member_200709006::BringCurrBook()
{
    return exstBook;
}

void Member_200709006::MembershipTypeAssign(string &s)
{
	//Making diciplined outro as below just like the pdf as:
    //    a. Student
    //    b. Personnel
    //    c. Faculty Member.
    if (s=="Student" || s=="Personnel" || s=="FacultyMember")
    {
        membershipType = s;
    }
    else
    {
        cout << "Error! There is not such a member type, setting up to 'Student'." << endl
             << "Membership types are limited by: 'Student', 'Personnel', 'FacultyMember'"<< endl;
        membershipType = "Student";
    }
}

void Member_200709006::UpdateId(int n)
{
    memberId = n;
}

int Member_200709006::GetMemberId()
{
    return memberId;
}
