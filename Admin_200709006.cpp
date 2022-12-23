
#include "Admin_200709006.h"

using namespace std;

void Admin_200709006::AddBook(Book_200709006 books[], int aWidth)
{
    bool bookDoesntExist = true;
    //Making book addition outros.(I also added publish date,because on pdf says we need add.)
    static string name;
    static string author;
    static string pub;

    cout << setw(15) << left << "Book Name: ";
    cin >> name;

    cout << setw(15) << left << "Author Name: ";
    cin >> author;

    cout << setw(15) << left << "Publish Date [DAY-MONTH-YEAR]: ";
    cin >> pub;

    for (int i=0;i<aWidth-1;i++)
    {
        string title = books[i].GetTitle();
        string desnAuthor = books[i].TakeAuthorsNm();

        if (title==name && desnAuthor==author)
        {
            bookDoesntExist = false;
            break;
        }
    }

    if (bookDoesntExist)
    {
        Book_200709006 cBook;

        cBook.SetAuthor(author);
        cBook.SetTitle(name);
        cBook.SetPubDate(pub);
        cBook.SetStatus("Unhold");

        for (int i=0; i<aWidth; i++){
            if (books[i].GetTitle().empty())
            {
                cBook.UpdateId(i);
                books[i] = cBook;
                break;
            }
        }
        cout << "Book added to library database successfully." << endl << endl;
    }
    else
    {
        cout << "This book is already in the library database." << endl << endl;
    }
}

void Admin_200709006::BooksList(Book_200709006 books[], int aWidth)
{
    //The book table on admin page.
    if (books[0].GetTitle().empty())
    {
        cout << "Currently there are no books in library database." << endl;
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

void Admin_200709006::DeleteBook(Book_200709006 books[], int aWidth)
{
	//Making book delete outro.
    int choice;
    cout << setw(15) << left << "Please enter the book's ID': ";
    cin >> choice;
    //For delete a book on admin menu,user need to give the book ID.

    DeleteItemFromArray(books, aWidth, choice);

    cout << "This book is deleted from library database successfully." << endl;

}

void Admin_200709006::AddUser(Member_200709006 users[], int aWidth)
{
    cout << "Enter Member Info" << endl;
    bool userDoesntExist = true;
    string nm;
    string usrnm;
    string membr;
    string usrToCheck;
    //Maked simplifed on words to use them more effectively and fast.Explanation: usr=user membr=member usrnm=username nm=name.
    //I had to do it because there are too many functions and variables must be same name.So i decided to make some of them more simple so they will not get involved each other and destroy the lookup.

    //Because of rules,when the user give exactly same name added before,the program will say "This account name is already taken by system.Please check again and make another."

    cout << setw(15) << left << "Name-Surname: ";
    cin >> nm;
    cout << setw(15) << left << "Account Name: ";
    cin >> usrnm;
    cout << setw(15) << left << "Membership Type: ";
    cin >> membr;

    for (int i=0;i<aWidth-1;i++)
    {
        usrToCheck = users[i].TaknUsername();
        if (usrnm==usrToCheck)
        {
            userDoesntExist = false;
            break;
        }
    }

    if (userDoesntExist)
    {
        Member_200709006 cMember;
        cMember.GiveName(nm);
        cMember.MembershipTypeAssign(membr);
        cMember.UsernameAs(usrnm);
        cMember.PasswordAs("temp");
        //First member password auto-maked by system as temp.
        cMember.MakeExistingBooksRes();

        for (int i=0; i<aWidth-1;i++)
        {
            if (users[i].TaknUsername().empty())
            {
                cMember.UpdateId(i);
                users[i] = cMember;
                break;
            }
        }
        cout << "This member is added to system successfully." << endl;
    }
    else
    {
        cout << "This account name is already taken by system.Please check again and make another." << endl;
    }
}

void Admin_200709006::ListUsers(Member_200709006 users[], int aWidth)
{
    if (users[0].TaknUsername().empty())
    {
        cout << "Currently there are no users in system.Please add a user to system before listing!" << endl;
        //Listing already added members.If there are no members added by admin,this outro will shown.
    }
    else
    {
    	//Decorasing and measuring the table.
        cout << setw(5)  << left <<"ID";
        cout << setw(20) << left <<"Full Name";
        cout << setw(20) << left <<"    Member Type";
        cout << setw(20) << left <<"    Account Name" << endl;

        for (int i=0;i<aWidth-1;i++)
        {
            if (!users[i].TaknUsername().empty())
            {
                cout << setw(5)  << left << users[i].GetMemberId();
                cout << setw(15) << left << users[i].GetName() << "          ";
                cout << setw(15) << left << users[i].MembershipType() << "          ";
                cout << setw(15) << left << users[i].TaknUsername() << endl;
            }
        }
    }
}

void Admin_200709006::DeleteUser(Member_200709006 users[], int aWidth)
{
    string userInp;
    int delIndex;
    //Deleting a user on administration page.

    cout << "The name of the account you want to delete: ";
    cin >> userInp;

    for (int i=0; i<aWidth;i++)
    {
        if (users[i].TaknUsername()==userInp)
        {
            delIndex = i;
        }
    }

    DeleteItemFromArray(users, aWidth, delIndex);

    cout << "This member removed from system successfully." << endl;
}

void Admin_200709006::UsernameAs(string usr)
{
    username = usr;
}

void Admin_200709006::PasswordAs(string password)
{
    password = password;
}

template<typename T>
void Admin_200709006::DeleteItemFromArray(T arr, int aWidth, int ind)
{
    for (int i=ind; i<aWidth-1; i++)
    {
        arr[i] = arr[i+1];
        arr[i].UpdateId(i);
    }
}
