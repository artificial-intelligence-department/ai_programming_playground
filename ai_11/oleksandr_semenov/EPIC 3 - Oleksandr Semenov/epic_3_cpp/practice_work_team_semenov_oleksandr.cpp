#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> libraryCatalog = {"The Great Gatsby", "To Kill a Mockingbird", "Brave New World", "The Catcher in the Rye"};
    vector<bool> lendingStatus = {true, true, true, true};
    int selection;
    string bookTitle;

    startMenu:
    cout << "Library Management System\n";
    cout << "1. List all books\n";
    cout << "2. Check out a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Enter your selection: ";
    cin >> selection;

    switch (selection) {
        case 1:
            for (int i = 0; i < libraryCatalog.size(); i++) {
                cout << i + 1 << ". " << libraryCatalog[i] << (lendingStatus[i] ? " (Available)" : " (Checked Out)") << "\n";
            }
            break;
        case 2:
            cin.ignore();
            cout << "Enter book title to check out: ";
            getline(cin, bookTitle);

            for (const auto &book : libraryCatalog) {
                if (book == bookTitle) {
                    int index = &book - &libraryCatalog[0];
                    if (lendingStatus[index]) {
                        lendingStatus[index] = false;
                        cout << "Book successfully checked out!\n";
                        break;
                    } else {
                        cout << "Book is already checked out.\n";
                    }
                    break;
                }
            }
            break;
        case 3:
            cin.ignore();
            cout << "Enter book title to return: ";
            getline(cin, bookTitle);

            for (const auto &book : libraryCatalog) {
                if (book == bookTitle) {
                    int index = &book - &libraryCatalog[0];
                    if (!lendingStatus[index]) {
                        lendingStatus[index] = true;
                        cout << "Book successfully returned!\n";
                        break;
                    } else {
                        cout << "Book was not checked out.\n";
                    }
                    break;
                }
            }
            break;
        case 4:
            cout << "Thank you for using the Library Management System!\n";
            return 0;
        default:
            cout << "Invalid selection. Please choose from the available options.\n";
            goto startMenu;
    }

    char continueChoice;
    do {
        cout << "Would you like to perform another operation? (Y/N): ";
        cin >> continueChoice;
    } while (continueChoice != 'Y' && continueChoice != 'N' && continueChoice != 'y' && continueChoice != 'n');

    if (continueChoice == 'Y' || continueChoice == 'y') {
        goto startMenu;
    } else {
        cout << "Thank you for using the Library Management System!\n";
    }

    return 0;
}
