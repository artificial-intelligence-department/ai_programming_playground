#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> books = {"Harry_Potter", "Hobbit", "Pride_and_Prejudice", "1984"};
    vector<bool> availability(books.size(), true);

    string userstring, takebooks, takemenu, mainmenu, bookscheks;
    string spusok("spusok"), take("take"), returnbook("return"), exit_program("exit");

    bool exitprogram = true;

    label1:
    while (exitprogram)
    {
        cout << "Enter the action (Example: spusok, take, return, exit): ";
        cin >> userstring;

        if (userstring == spusok)
        {
            cout << "List of available books:" << endl;
            for (int i = 0; i < books.size(); i++)
            {
                if (availability[i])
                    cout << books[i] << " (Available)" << endl;
                else
                    cout << books[i] << " (Not Available)" << endl;
            }
            cout << "Do you want to return to the main menu (yes / no): ";
            cin >> mainmenu;
            if (mainmenu == "no")
            {
                exitprogram = false;
            }
        }
        else if (userstring == take)
        {
            cout << "Enter the name of the book you want to take( enter with _ ): ";
            cin >> takebooks;

            bool bookTaken = false;
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i] == takebooks && availability[i])
                {
                    cout << "You have taken the book: " << books[i] << endl;
                    availability[i] = false;
                    bookTaken = true;
                    break;
                }
            }

            if (bookTaken == false) //  перевірка чи книгу вдалося взяти 
            {
                cout << "Book not found or already taken." << endl;
            }

            cout << "Do you want to return to the main menu (yes / no): ";
            cin >> mainmenu;
            if (mainmenu == "no")
            {
                exitprogram = false;
            }
            else
            {
                userstring = ""; 
            }
        }
        else if (userstring == returnbook)
        {
            cout << "Enter the name of the books you want to return (Enter with _): ";
            cin >> bookscheks;
            bool bookTaken = true;
            for(int i = 0; i < books.size(); i++)
            {
                if (books[i] == bookscheks && availability[i] == false)
                {
                    cout << "You have return the book: " << books[i] << endl;
                    availability[i] = true;
                    bookTaken = false;
                    break;
                }
            }

            if (bookTaken == true)
            {
                cout << "Book not found or not taken." << endl;
            }

            cout << "Do you want to return to the main menu (yes / no): ";
            cin >> mainmenu;

            if (mainmenu == "no")
            {
                exitprogram = false;
            }
            else
            {
                userstring = ""; 
            }

        }
        else if (userstring == exit_program)
        {
            exitprogram = false;
        }
        else
        {
            cout << "Undefined command" << endl;
            goto label1;
        }
    }

    return 0;
}
