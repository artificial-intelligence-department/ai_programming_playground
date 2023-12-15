#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;



int main()
{
    vector<string> books;
    books = { "50 shapes of grey", "Harry Potter", "Zakhar Berkut", "Kobzar", "Faust", "1984", "Vacation" };
    vector<string> available;
    available = books;
    int size = books.size();
    int choice = 0;
    while (true)
    {
    tryagain0:
        cout << "1 - list the books\n2 - borrow a book\n3 - return a book\n4 - check avaibility of a book\n5 - exit" << endl;
        cin >> choice;




        if (choice == 1)
        {
            cout << "\033[35m" << "All existing books:" << "\033[37m" << endl;
            for (int i = 0; i < size; i++)
            {
                cout << books[i] << endl;
            }
            cout << endl;
            cout << "\033[35m" << "Available books:" << "\033[37m" << endl;
            for (string x : available)
            {
                if (x != "none")
                {
                    cout << "\033[32m" << x << "\033[37m" << endl;
                }
            }
            cout << endl;
        }

        if (choice == 2)
        {
            cin.ignore(30000, '\n');
            string strchoice;
            do
            {
                cout << "Enter the name of a book or type <<return>> to quit: ";
                getline(cin, strchoice);

                bool ok = false;
                for (int i = 0; i < size; i++)
                {
                    if (strchoice == available[i])
                    {
                        available[i] = "none";
                        ok = true;
                    }

                }
                if (ok)
                {
                    cout << "\033[32m" << "You successfully borrowed a book" << "\033[37m" << endl;
                }
                if (!ok && strchoice != "return")
                {
                    cout << "\033[31m" << "There is no such book. Try again" << "\033[37m" << endl;
                }
            } while (strchoice != "return");
        }
        if (choice == 3)
        {
            cin.ignore(30000, '\n');
            string strchoice2;
            do
            {
                cout << "Enter the name of a book you want to return or type <<return>> to quit: ";
                getline(cin, strchoice2);
                bool ok2 = false;
                for (int i = 0; i < size; i++)
                {
                    if (strchoice2 == books[i] && available[i] == "none")
                    {
                        available[i] = strchoice2;
                        ok2 = true;
                    }

                }
                if (ok2)
                {
                    cout << "\033[32m" << "You successfully returned the book" << "\033[37m" << endl;
                }
                if (!ok2 && strchoice2 != "return")
                {
                    cout << "\033[31m" << "The book doesn't belong to our library or is already available" << "\033[37m" << endl;

                }
            } while (strchoice2 != "return");
        }
        if (choice == 4)
        {
            cin.ignore(30000, '\n');
            string strchoice3;
            do
            {
                cout << "Enter the name of a book you want to check on avaibility: ";
                getline(cin, strchoice3);
                bool ok3 = false;
                for (string y : available)
                {
                    if (y == strchoice3)
                    {
                        ok3 = true;
                    }

                }
                if (ok3)
                {
                    cout << "\033[32m" << "The book is available" "\033[37m";
                }
                if (!ok3 && strchoice3!="return")
                {
                    cout << "\033[31m" <<  "The book isn't available" << "\033[37m";
                }
                cout << endl;
            } while (strchoice3 != "return");

        }
        if (choice == 5)
        {
            cout << "\033[36m" << "Powered by Daniil Shevchenko. Googbye" << "\033[37m";
            Sleep(3000);
            break;
        }
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(30000, '\n');
            goto tryagain0;
        }



    }
}
