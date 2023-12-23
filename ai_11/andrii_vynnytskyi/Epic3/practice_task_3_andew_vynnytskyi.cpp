#include <iostream>
#include <vector>

using namespace std;

void print_array(vector<string> books , vector<bool> available);
void take_book(vector<string> books , vector<bool> &available , string book_name);
void return_book(vector<string> books , vector<bool> &available, string book_name);

int main() {
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> available = {1, 1, 1, 1};
    int choice;
    string bookName;


    menu:
    cout << "Library Management\n"
            "1. List all books\n"
            "2. Borrow a book\n"
            "3. Return a book\n"
            "4. Exit\n"
            "Enter your choice: ";
    cin >> choice;


    switch(choice) {
        case 1:
            print_array(books, available);
            break;
        case 2:
            cin.ignore();
            cout << "Enter book name to borrow: ";
            getline(cin, bookName);


            take_book(books, available, bookName);
            break;
        case 3:
            cin.ignore();
            cout << "Enter book name to return: ";
            getline(cin, bookName);

            return_book(books, available, bookName);

            break;
        case 4:
            cout << "Goodbye!";
            break;
        default:
            cout << "Invalid choice.\n";
            goto menu;
    }


    string continue_choice;
    do {
        cout << "Do you want to perform another operation?\n - Yes\n - No: ";
        cin >> continue_choice;
    } while (continue_choice != "Yes" && continue_choice != "No" );


    if (continue_choice == "Yes") {
        goto menu;
    } else {
        cout << "Goodbye!";
    }


    return 0;
}

void print_array(vector<string> books , vector<bool> available)
{

    for (int i = 0; i < books.size();i++)
    {
        cout<< books[i]<< ": "<< (available[i] ? "Available" : "Borrowed") << "\n";
    }
}
void take_book(vector<string> books , vector<bool> &available, string book_name)
{
    for (string &book: books)
    {
        if (book == book_name)
        {
            int index = &book - &books[0];
            if (available[index])
            {
                available[index] = 0;
                cout << "You successfully take the book\n";
                return;
            }
            else
            {
                cout<<"This book are borrowed\n";
                return;
            }
        }
    }
}
void return_book(vector<string> books , vector<bool> &available, string book_name)
{
    for (string &book: books)
    {
        if (book == book_name)
        {
            int index = &book - &books[0];
            if (!available[index])
            {
                available[index] = 1;
                cout << "You successfully return the book\n";
                return;
            }
            else
            {
                cout<<"This book aren't borrowed\n";
                return;
            }
        }
    }
}
