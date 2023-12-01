#include <iostream>
#include <string>
#include <vector>


using namespace std;

void displayMenu() {
    cout << "Library Management\n";
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    vector<string> books = {"Harry Potter", "Clean code", "Sherlock Holms", "Karlson", "Kobzar"};
    vector<bool> available = {true, true, true, true, true};
    int choice;
    string bookName;

     while (true) {
        displayMenu();
        cin >> choice;

    switch(choice) {
        case 1: 
            for (int i = 0; i < 5; i++) {
                cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << "\n";
            }
            break;
        case 2:
            cin.ignore();
            cout << "Enter book name to borrow: ";
            getline(cin, bookName);

            for (const auto &book : books) {
                if (book == bookName) {
                    int index = &book - &books[0];
                    if (available[index]) {
                        available[index] = false;
                        cout << "Book borrowed successfully!\n";
                    } else {
                        cout << "Book is already borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 3:
            cin.ignore();
            cout << "Enter book name to return: ";
            getline(cin, bookName);

            for (const auto &book : books) {
                if (book == bookName) {
                    int index = &book - &books[0];
                    if (!available[index]) {
                        available[index] = true;
                        cout << "Book returned successfully!\n";
                    } else {
                        cout << "Book is not borrowed.\n";
                    }
                    break;
                }
            }
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
    }

   }

    return 0;
}
