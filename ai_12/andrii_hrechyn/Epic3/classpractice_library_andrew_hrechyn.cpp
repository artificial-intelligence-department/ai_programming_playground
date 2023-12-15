#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> books = {"It", "The Hobbit", "The Great Gatsby", "1984"};
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
            goto menu;
    }


    char continueChoice;
    do {
        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> continueChoice;
    } while (continueChoice != 'Y' && continueChoice != 'N' && continueChoice != 'y' && continueChoice != 'n');


    if (continueChoice == 'Y' || continueChoice == 'y') {
        goto menu;
    } else {
        cout << "Goodbye!";
    }


    return 0;
}
