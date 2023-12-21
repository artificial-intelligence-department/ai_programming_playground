#include <iostream>
#include <string>
using namespace std;

constexpr int Books = 6;

int main()
{
    string n, x;
    string Books_Names[Books] = {
        "1984", "The Great Gatsby", "Lolita", "To Kill a Mockingbird",
        "Beloved", "The Lord of the Rings"};
    bool Available_Books[Books] = {true, false, true, false, false, true};
Menu:

    cout << "We have this books" << endl;
    for (int i = 0; i < Books; i++)
    {
        if (Available_Books[i])
        {
            cout << Books_Names[i] << endl;
        }
    }

    cout << "Choose your action? \n return or take" << endl;
    cin >> n;

    if (n == "take")
    {
        cout << "which book do you choose?" << endl;
        cin >> x;
        for (int i = 0; i < Books; i++)
        {
            if (x == Books_Names[i] && Available_Books[i])
            {
                Available_Books[i] = false;
                cout << "The book was successfully taken" << endl;
                goto Menu;
            }
        }
        cout << "There is no such available book" << endl;
        goto Menu;
    }
    else if (n == "return")
    {
        cout << "which book do you return?" << endl;
        cout << "We dont have this books" << endl;
        for (int i = 0; i < Books; i++)
        {
            if (!Available_Books[i])
            {
                cout << Books_Names[i] << endl;
            }
        }
        cin >> x;
        for (int i = 0; i < Books; i++)
        {
            if (x == Books_Names[i] && !Available_Books[i])
            {
                Available_Books[i] = true;
                cout << "The book was successfully returned" << endl;
                goto Menu;
            }
        }
        cout << "There is no such absent book" << endl;
        goto Menu;
    }
    else
    {
        cout << "Input is invalid" << endl;
        goto Menu;
    }

    return 0;
}