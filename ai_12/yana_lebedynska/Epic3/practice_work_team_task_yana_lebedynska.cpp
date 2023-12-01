#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
    string operation, available, bookName;
    char continueWork;

menu:
    cout << "Hi! You have just entered our mini-library!\n";
    cout << "Here you can:\n";
    cout << "1.view a list of all books (review)\n";
    cout << "2.view a list of available books (availability)\n";
    cout << "3.return a book (return)\n";

    vector<string> books(10);
    books = {"Harry Potter", "The great Gatsby", "The Little Prince", "The Hobbit", "Lolita", "Black Beauty", "The Hound of the Baskervilles", "The Bible", "The divine comedy", "The Picture of Dorian Gray"};

    vector<string> aBooks(7);
    aBooks = {"Harry Potter", "The Little Prince", "The Hobbit", "Lolita", "The Bible", "The divine comedy", "The Picture of Dorian Gray"};

    vector<string> notAvailableBooks(3);
    notAvailableBooks = {"The great Gatsby", "Black Beauty",  "The Hound of the Baskervilles"};

    cout << "Enter the operation you want to do: ";
    cin >> operation;

    if(operation == "review")
    {
        for(string book : books)
        {
            cout << book << ", ";
        }
    }

    else if(operation == "availability")
    {
        cout << "What book do you want? Enter here: ";
        cin >> available;

        bool bookAvailable = false;

        for(string aBook : aBooks)
        {
            if(aBook == available)
            {
                bookAvailable = true;
                cout << "This book is available, so you can take it";
                break;
            }
            else
            {
                cout << "This book isn't available now!";
                break;
            }
        }
    }

    else if(operation == "return")
    {
        cin.ignore();
        cout << "Enter the book you want to return: ";
        getline(cin, bookName); 

        for(const auto &book1 : aBooks)
        {
            if(book1 == bookName)
            {
                cout << "You can't retur this book! It's available now.";
            }
        }

        
        for(const auto &book2 : notAvailableBooks)
        {
            if(book2 == bookName)
            {
                cout << "You have returned the book successfully!";
            }
        }
    }

    else
    {
        cout << "This operation isn't found!\n";
        goto menu;
    }


    do
    {
        cout << "\nDo you want to enter another operation (enter 'y' or 'n'): ";
        cin >> continueWork;
        
        if(continueWork != 'y')
        {
            break;
        }
        else
        {
            goto menu;
        }
    }
    while(continueWork == 'y');
    
    return 0;
}
