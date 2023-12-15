#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> books = {"In Search of Lost Time", "Ulysses", " The Great Gatsby"," War and Peace"};
    vector<bool> available = {true, true, true, true};
    int choice;
    string bookName;

    menu:
    cout << "Library Management\n";
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
        case 1:
            for (int i = 0; i < books.size(); i++) {
                cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)\n": " (Borrowed)\n");
            }
            break;
        case 2:
            cin.ignore();
            cout << "Enter book name to borrow: ";
            getline(cin, bookName);
            for (size_t i = 0; i < books.size(); ++i) {
                if (books[i] == bookName && available[i]) {
                    available[i] = false;
                    cout << "Book borrowed successfully!\n";
                    break;
                }
            }
            break;
        case 3:
            cin.ignore();
            cout << "Enter book name to return: ";
            getline(cin, bookName);
            for (size_t i = 0; i < books.size(); ++i) {
                if (books[i] == bookName && !available[i]) {
                    available[i] = true;
                    cout << "Book returned successfully\n";
                    break;
                }
            }
            break;
        case 4:
            cout << "Goodbye!";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            goto menu;
    }

    char anotherOperation;
    do {
        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> anotherOperation;
    } while (anotherOperation != 'Y' && anotherOperation != 'N');

    if (anotherOperation == 'Y') {
        goto menu;
    } else {
        cout << "Goodbye!";
    }

    return 0;
}