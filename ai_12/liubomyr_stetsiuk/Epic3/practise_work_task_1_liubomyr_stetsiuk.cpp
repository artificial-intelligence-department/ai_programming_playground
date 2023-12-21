#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> library = {"Harry Potter", "Atomic Habbits", "Deep Work", "Ego is the enemy"};
    vector<bool> av = {true, true, true, true};
    int size = library.size();
    string action;
menu:

    cout << "Choose your option: \n";
    cout << "To see all books which we have type: Library \n";
    cout << "To borrow a book type: Borrow \n";
    cout << "To return a book type: Return \n";
    cout << "To quit library type: Quit \n";

    cin >> action;

    if (action == "library" || action == "Library")
    {
        for (string word : library)
        {
            cout << word << endl;
        }
        goto choose;
    }

    else if (action == "Borrow" || action == "borrow")
    {
        cout << "Enter the title of the book you want to borrow: ";
        cin.ignore();
        string bookTitle;
        getline(cin, bookTitle);

        bool found = false;
        for (int i = 0; i < size; ++i)
        {
            if (library[i] == bookTitle && av[i])
            {
                cout << "You have borrowed: " << bookTitle << endl;
                av[i] = false;
                library.erase(library.begin() + i);
                av.erase(av.begin() + i);
                found = true;
                break;
            }

            if (!found)
            {
                cout << "The book is either not available or doesn't exist in the library.\n";
                goto choose;
            }
        }
    }
    else if (action == "return" || action == "Return")
    {
        cout << "Enter the title of the book you want to return: ";
        cin.ignore();
        string returnedBook;
        getline(cin, returnedBook);

        library.push_back(returnedBook);
        av.push_back(true);
        size++;

        cout << "Book \" " << returnedBook << "\" has been added to the library.\n";
        goto choose;
    }
    else if (action == "quit" || action == "Quit")
    {
        return 0;
    }

choose:
    cout << "Do you want something else? (type Yes or No): ";
    string answer;
    cin >> answer;
    if (answer == "yes" || answer == "Yes")
    {
        goto menu;
    }
    else if (answer == "no" || answer == "No")
    {
        cout << "Good luck!";
        return 0;
    }
    else
    {
        cout << "You have wrote incorect word (You have to type Yes or Now) \n";
        goto choose;
    }

    return 0;
}