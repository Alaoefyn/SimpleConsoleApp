


#include <iostream>
#include <iomanip>
#include "Member_200709006.h"
#include "Book_200709006.h"
#include "Admin_200709006.h"

using namespace std;

int main()
{
    int arraySize = 100;
    Member_200709006 members[arraySize];
    Book_200709006 books[arraySize];

    Admin_200709006 admin;
    admin.PasswordAs("1234");
    admin.UsernameAs("admin");

    //Making the Main Menu / 1. Admin Login / 2. Member Login / 3. Exit / Enter Your Choice outros.
    int choice;
    string usr;
    string password;

    bool active = true;
    while (active)
    {
        cout << "Main Menu" << endl;
        cout << "1. Admin Login"<< endl <<
             "2. Member Login"<< endl <<
             "3. Exit"<< endl <<
             "Please Enter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << setw(15) << right << "Admin User Name: ";
                cin >> usr;

                cout << setw(15) << right << "Password: ";
                cin >> password;

                if (admin.LogIn(usr, password))
                {
                    cout << "Password Accepted!" << endl;
                    int adminChoice;

                    bool adminIsRunning = true;
                    while (adminIsRunning)
                    {
                    	//Admin menu configuration outro on compiler screen.
                        cout << "Admin Menu"<< endl;
                        cout << "1 Add Book"<< endl;
                        cout << "2 Delete Book"<< endl;
                        cout << "3 List Books"<< endl;
                        cout << "4 Add Member" << endl;
                        cout << "5 List Members" << endl;
                        cout << "6 Delete Member" << endl;
                        cout << "7 Exit" << endl;
                        cout << "Enter Your Choice: ";
                        cin  >> adminChoice;
                        switch (adminChoice)
                        {
                            case 1:
                                admin.AddBook(books, arraySize);
                                continue;
                            case 2:
                                admin.DeleteBook(books, arraySize);
                                continue;
                            case 3:
                                admin.BooksList(books, arraySize);
                                continue;
                            case 4:
                                admin.AddUser(members, arraySize);
                                continue;
                            case 5:
                                admin.ListUsers(members, arraySize);
                                continue;
                            case 6:
                                admin.DeleteUser(members, arraySize);
                                continue;
                            case 7:
                                adminIsRunning = false;
                                break;
                            default:
                                cout << "This choice is not valid! Please check again." << endl;
                                continue;
                        }
                    }
                }
                else
                {
                    cout << "You entered wrong username or password.Please check your login variables again." << endl;
                }
                continue;
            }

            case 2:
            {
                bool activeMember = true;
                bool loggedIn = false;

                int selectnMember;
                string usrInpt;
                string pswrInpt;
                //Program wants here a username and password from user.

                cout << "Member User Name: ";
                cin >> usrInpt;
                cout << "Password: ";
                cin >> pswrInpt;

                for (int i=0; i<arraySize; i++)
                {
                    if (members[i].LogIn(usrInpt, pswrInpt))
                    {
                        loggedIn = true;
                    }
                }

                if (loggedIn)
                {
                    cout << "Password Accepted!" << endl;
                    while (activeMember)
                    {
                    	//Member menu config outro.
                        cout << "Member Menu"          << endl;
                        cout << "1. Find Book"         << endl;
                        cout << "2. Borrow Book"       << endl;
                        cout << "3. Return Book"       << endl;
                        cout << "4. List Books"        << endl;
                        cout << "5. Member Operations" << endl;
                        cout << "6. Exit"              << endl;
                        cout << "Enter Your Choice: ";
                        cin>>selectnMember;
                        switch (selectnMember)
                        {
                            case 1:
                                members->TypedBookFound(books, arraySize);
                                continue;
                            case 2:
                                members->TakeTheBook(usrInpt, members, books, arraySize);
                                continue;
                            case 3:
                                members->GivingBackTheBook(usrInpt, members, books, arraySize);
                                continue;
                            case 4:
                                members->BooksList(books, arraySize);
                                continue;
                            case 5:
                                members->PassContConfiguration(usrInpt, members, arraySize);
                                continue;
                            case 6:
                                activeMember = false;
                                break;
                            default:
                                cout << "This choice is not valid! Please check again!" << endl;
                                continue;
                        }
                    }
                }
                else
                {
                	//Here is the outro which if user give a wrong name-password.But on program.It will say this message for non-members too.
                    cout << "You entered wrong username or password(Or system admin is not added you on system database).Please check your login variables again." << endl;
                }
                continue;
            }

            case 3:
                active=false;
                break;

            default:
                cout << "You choosed a invalid option!Please check again!" << endl;
                continue;
        }
    }
    return 0;
}
