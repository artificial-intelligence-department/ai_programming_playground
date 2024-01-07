#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int main()
{

    vector<string> books;
    books.push_back("Harry Potter");
    books.push_back("Honey and milk");
    books.push_back("1984");
    books.push_back("Kafka on the shore");

    vector<bool> availability;
    availability.push_back(true);
    availability.push_back(true);
    availability.push_back(true);
    availability.push_back(true);

    int choice;
    string bookName;

    while (true)
    {
        cout << "Library\n";
        cout << "1. List of all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < books.size(); i++)
            {
                cout << i + 1 << ". " << books[i] << (availability[i] ? " (Available)" : " (Borrowed)") << "\n";
            }
            break;

        case 2:
            cin.ignore();
            cout << "Enter book name to borrow: ";
            getline(cin, bookName);

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i] == bookName)
                {
                    if (availability[i])
                    {
                        availability[i] = false;
                        cout << "Book has been borrowed successfully!\n";
                    }
                    else
                    {
                        cout << "Book is already borrowed(.\n";
                    }
                    break;
                }
                if (i == books.size() - 1)
                {
                    cout << "Oops, I dont know this book.\n";
                }
            }
            break;

        case 3:
            cin.ignore();
            cout << "Enter book name to return: ";
            getline(cin, bookName);

            for (int i = 0; i < books.size(); i++)
            {
                if (books[i] == bookName)
                {
                    if (!availability[i])
                    {
                        availability[i] = true;
                        cout << "Book has been returned successfully!\n";
                    }
                    else
                    {
                        cout << "Book wasn't returned(.\n";
                    }
                    break;
                }
                if (i == books.size() - 1)
                {
                    cout << "Oops.\n";
                }
            }
            break;

        case 4:
            cout << "Goodbye!";
            return 0;

        default:
            cout << "Invalid choice.\n";
        }

        char secondChoice;
        do
        {
            cout << "Do you want to perform another operation?) (Y/N): ";
            cin >> secondChoice;
        } while (secondChoice != 'Y' && secondChoice != 'N' && secondChoice != 'y' && secondChoice != 'n');

        if (secondChoice == 'N' || secondChoice == 'n')
        {
            cout << "Goodbye, have a nice day!)";
            break;
        }
    }

    return 0;
}
