#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBooks(const vector<string>& books, const vector<bool>& available) {
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << "\n";
    }
}

int main() {
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> available(books.size(), true);

    int choice;
    string bookName;

    while (true) {
        cout << "Library Management\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Listing all books:\n";
                displayBooks(books, available);
                break;
            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, bookName);

                for (size_t i = 0; i < books.size(); ++i) {
                    if (books[i] == bookName) {
                        if (available[i]) {
                            available[i] = false;
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

                for (size_t i = 0; i < books.size(); ++i) {
                    if (books[i] == bookName) {
                        if (!available[i]) {
                            available[i] = true;
                            cout << "Book returned successfully!\n";
                        } else {
                            cout << "Book wasn't borrowed.\n";
                        }
                        break;
                    }
                }
                break;
            case 4:
                cout << "Goodbye!";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }

        char continueChoice;
        do {
            cout << "Do you want to perform another operation? (Y/N): ";
            cin >> continueChoice;
            continueChoice = toupper(continueChoice);
        } while (continueChoice != 'Y' && continueChoice != 'N');

        if (continueChoice == 'N') {
            cout << "Goodbye!";
            break;
        }
    }

    return 0;
}
