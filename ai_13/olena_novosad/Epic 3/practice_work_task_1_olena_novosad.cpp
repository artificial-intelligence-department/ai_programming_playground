

#include <iostream>
#include <string>

using namespace std;

const int amount = 5;
string bookNames[amount] = {"1984", "Hamlet", "The little prince", "The secret history", "Misto"};
bool bookAvailabilities[amount] = {true, true, true, true, true};

int main()
{
    char answer;
    while (true)
    {
        do
        {

        start:

            char action;
            printf(" (1)List of books\n (2)Take a book\n (3)Return a book\nChoose action: ");
            cin >> action;

            if (action == '1')
            {
                for (int i = 0; i < amount; i++)
                {
                    cout << (i + 1) << ") " << bookNames[i] << "\n";
                }
            }
            else if (action == '2')
            {
                cout << "Books which are available: \n";
                int i = 0;
                for (auto available : bookAvailabilities)
                {
                    if (available)
                    {
                        cout << (i + 1) << ") " << bookNames[i] << "\n";
                    }
                    i++;
                }

                cout << "\nWhich one would you like to take, enter the index?\n";
                int index;
                cin >> index;
                index--; 
                if (index >= 0 && index < amount)
                {
                    if (bookAvailabilities[index])
                    {
                        bookAvailabilities[index] = false;
                        cout << "You took " << '"' << bookNames[index] << '"' << endl;
                    }
                    else
                    {
                        cout << "The book is not available\n";
                    }
                }
                else
                {
                    cout << "You entered not exsisting index\n\n";
                    goto start;
                }
            }
            else if (action == '3')
            {
                cout << "Which book would you like to return, enter the index?\n";
                int index;
                cin >> index;
                index--; 
                if (index >= 0 && index < amount)
                {
                    if (!bookAvailabilities[index])
                    {
                        bookAvailabilities[index] = true;
                        cout << "You returned book " << '"' << bookNames[index] << '"' << endl;
                    }
                    else
                    {
                        cout << "Oops, this book is already here\n";
                    }
                }
                else
                {
                    cout << "You entered not existing index\n\n";
                    goto start;
                }
            }
            else
            {
                cout << "incorrect answer\n\n";
                goto start;
            }

            cout << "Do you want to do another action (y/n)?\n";
            cin >> answer;

            if (answer != 'y' && answer != 'n')
            {
                cout << "incorrect answer\n\n";
                goto start;
            }

        } while (answer == 'y');

        cout << "Exit? (y/n)\n";
        cin >> answer;

        if (answer == 'y')
        {
            break;
        }
        else if (answer == 'n')
        {
            continue;
        }
        else
        {
            cout << "incorrect answer\n\n";
            goto start;
        }
    }

    return 0;
}