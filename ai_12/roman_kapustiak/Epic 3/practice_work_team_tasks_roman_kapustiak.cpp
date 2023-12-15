// Library manager
#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> status = {true, true, true, true};
    
    int size = books.size();
    string bookName, action;


    while(true)
    {
    menu:
        cout << "\nEnter: 1 - show books, 2 - take book, 3 - return book, 4 - exit.\n";

        cin >> action;

        if(action.length() != 1)
        {
            cout << "Wrong input!\n";
            goto menu;
        }

        switch (action[0])
        {
        case '1':
            // Show books
            for (int i = 0; i < size; i++)
                cout << books[i] << " - " << (status[i] ? "" : "not") << " available\n";
            break; 

        case '2':
            // Take book
            cout << "Enter name of the book you want to take\n";

            cin.ignore();
            getline(cin, bookName);

            for (const auto &book : books)
            {
                if (book == bookName)
                {
                    if (status[&book - &books[0]])
                    {   
                        cout << "You took the book " << book << endl;
                        status[&book - &books[0]] = false;
                    }
                    else
                    {
                        cout << "You can't take the book " << book << endl;
                    }
                    break;
                }                
            }
            break;

        case '3':
            // Return book
            cout << "Enter name of the book you want to return\n";

            cin.ignore();
            getline(cin, bookName);

            for (const auto &book : books)
            {
                if (book == bookName)
                {
                    if (!(status[&book - &books[0]]))
                    {   
                        cout << "You returned the book " << book << endl;
                        status[&book - &books[0]] = true;
                        break;
                    }
                    else
                    {
                        cout << "You can't return the book " << book << endl;
                        break;
                    }
                }                
            }

            break;

        case '4':
            // Exit
            cout << "Goodbye!\n";
            return 0;

            break;
        
        default:
            cout << "Wrong input!\n";
            goto menu;
            break;
        }

        do
        {
            cout << "Continue? (y / n): ";
            cin >> action;

            if (action == "n" || action == "N")
                return 0;
        }
        while (action != "y" && action != "Y");
    }    
    
    return 0;
}
