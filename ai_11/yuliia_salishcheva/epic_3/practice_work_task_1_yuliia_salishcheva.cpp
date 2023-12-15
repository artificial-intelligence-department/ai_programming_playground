#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int bookscode1, bookscode2;
    char command;
    vector<pair<string, int>> books = { make_pair("Book C++", 1111),  make_pair("Book C#", 1112), make_pair("Book C", 1113), make_pair("Book Python", 1114) };
    vector<pair<int, bool>> books_available = { make_pair(1111, true), make_pair(1112, true), make_pair(1113, false), make_pair(1114, true) };



    do {
        cout << "| Library |" << endl;
        cout << "| Count of books [c]: " << endl;
        cout << "| Take a book [t]: " << endl;
        cout << "| Return the book [r]: " << endl;
        cout << "| Exit [e]: " << endl;
        cout << endl << endl;
    invalid_input:
        cout << "| Enter command: ";
        cin >> command;
        if (command != 'c' && command != 't' && command != 'r' && command != 'e' && command != 'C' && command != 'T' && command != 'R' && command != 'E')
        {
            cout << "| Wrong command!" << endl;
            goto invalid_input;
        }
        if (command == 'C' || command == 'T' || command == 'R' || command == 'E')
        {
            command = tolower(command);
        }
        switch (command)
        {
        case 'c':
        {
            cout << "| List of books: " << endl;

            for (int i = 0, j = 0; i < books.size() && j < books_available.size(); i++, j++)
            {
                cout << i + 1 << "| " << books[i].first;
                if (books_available[j].second)
                {
                    cout << " [" << books_available[j].first << "] " << "- Available:)" << endl;
                }
                else
                {
                    cout << " [" << books_available[j].first << "] " << " - Not available! " << endl;
                }
            }
            cout << endl;
            break;
        }
        case 't':
        {
            cout << "| Enter book's code: ";
            cin >> bookscode1;
            bool book = false;
            for (int i = 0; i < books_available.size(); i++)
            {
                if (books_available[i].first == bookscode1 && books_available[i].second == true)
                {
                    cout << "Take " << books[i].first << " Good reading!!\n" << endl;
                    books_available[i].second = false;
                    book = true;
                    break;
                }
            }
            if (!book)
                cout << "Unfortunately, the book is not available:(" << endl;
            break;
            cout << endl;
        }
        case 'r':
        {
            cout << "| Enter book's code: ";
            cin >> bookscode2;
            bool book = false;
            for (int i = 0; i < books_available.size(); i++)
            {
                if (books_available[i].first == bookscode2 && books_available[i].second == false)
                {
                    cout << books[i].first << "- the book is taken, thank you:) " << endl;
                    books_available[i].second = true;
                    book = true;
                    break;
                }

            }
            if (!book)
                cout << "The book is already there :(!!!!!!!!!" << endl;
            break;
            cout << endl;
        }

        }
    } while (command != 'e');
    cout << "Good bye <3" << endl;
}