#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool correct = true;
    while (correct)
    {
        vector<string> books = {
            "Fallout",
            "God of war",
            "Metro 2033",
            "Metro 2035",
        };
    start:
        cout << "If you want to check which books are available type: \"Menu\"" << endl;
        cout << "To check how many books are available type: \"Quantity\"" << endl;
        cout << "If you want to end type \"End\"" << endl;

        string word;
        cin >> word;
        if (word == "Menu" || word == "menu")
        {
        menu:
            for (string book1 : books)
            {
                cout << endl;
                cout << book1 << endl;
            }
            cout << endl;
            cout << " If you want to take any book type \"Take\"" << endl;
            cout << " If you want to return book type \"Return\"" << endl;
            cout << " If you want to check quantity type \"Quantity\"" << endl;
            cout << " If you want to end type \"End\"" << endl;
            string word1;
            cin >> word1;
            if (word1 == "Take" || word1 == "take")
            {
                cout << endl;
                cout << " Write name of book you would like to take: " << endl;
                string takeB;

                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            takeBook:

                getline(cin, takeB);
                bool bookFound = false;
                for (const string book : books)
                {
                    if (book == takeB)
                    {
                        auto it = find(books.begin(), books.end(), book);

                        if (it != books.end())
                        {
                            books.erase(remove(books.begin(), books.end(), takeB), books.end());
                            bookFound = true;
                        }

                        goto start;
                    }
                }

                if (!bookFound)
                {
                    cout << "You write a wrong book! Try again: " << endl;
                    goto takeBook;
                }
            }
            else if (word1 == "return" || word1 == "Return")
            {
                cout << " Write name of book you want to return" << endl;
                string bookRet;
                cin.clear();
                cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

                getline(cin, bookRet);
                books.push_back(bookRet);
            typeMenu:
                cout << "Type \"menu\" to go to the menu" << endl;
                string word2;
                cin >> word2;
                if (word2 == "menu" || word2 == "Menu")
                {
                    goto menu;
                }
                else
                {
                    goto typeMenu;
                }
            }
            else if (word1 == "end" || word1 == "End")
            {
                goto pos5;
            }
            else if (word1 == "Quantity" || word1 == "quantity")
            {
                goto pos6;
            }
            else
            {
                goto menu;
            }
            correct = false;
        }
        else if (word == "quantity" || word == "Quantity")
        {
        pos6:
            int quant = 0;
            for (string book1 : books)
            {
                quant++;
            }
            cout << quant << endl;
            cout << "If you want to return back type \"Back\"";
            string word2;
            cin >> word2;
            if (word2 == "Back" || word2 == "back")
            {
                goto start;
            }
            correct = false;
        }
        else if (word == "end" || word == "End")
        {
            goto pos5;
        }
        else
        {
            goto start;
        }
    }
pos5:
    return 0;
}