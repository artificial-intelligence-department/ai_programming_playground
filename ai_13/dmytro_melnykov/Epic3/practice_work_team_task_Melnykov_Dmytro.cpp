#include<iostream>
#include<string>
using namespace std;

int main()
{
    string Books[4] = {"Sherlock Holms", "The Theory of Lie", "Alice in Wonderland", "1984"};
    bool available[4] = {true, true, true, true};
    int a;
    string NameBook;

    storage:
    cout << "Library Management" << endl;
    cout << "1. List all books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> a;

    if (a == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << i + 1 << ". " << Books[i] << (available[i] ? " (Available)" : " (Borrowed)") << endl;
        }
        cout << endl;
    }
    else if (a == 2)
    {
        cout << "Enter your book name:";
        cin >> NameBook;

        for (int i = 0; i < 4; i++)
        {
            if (Books[i] == NameBook)
            {
                if (available[i])
                {
                    available[i] = false;
                    cout << "You successfully borrowed your book" << endl;
                }
                else
                {
                    cout << "Your book is already borrowed" << endl;
                }
                break;
            }
        }
    }
    else if (a == 3)
    {
        cout << "Enter your book name:";
        cin >> NameBook;

        for (int i = 0; i < 4; i++)
        {
            if (Books[i] == NameBook)
            {
                if (!available[i])
                {
                    available[i] = true;
                    cout << "You successfully returned your book" << endl;
                }
                else
                {
                    cout << "Your book isn't borrowed" << endl;
                }
                break;
            }
        }
    }
    else if (a == 4)
    {
        cout << "Goodbye";
        return 0;
    }

    goto storage;
}
