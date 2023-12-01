#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> titles = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> status = {true, true, true, true};
    int selection;
    string titleName;
    char continueSelection;

    do {
        cout << "Library Management\n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your selection: ";
        cin >> selection;

        switch(selection) {
            case 1: 
                for (int i = 0; i < titles.size(); i++) {
                    cout << i + 1 << ". " << titles[i] << (status[i] ? " (Available)" : " (Borrowed)") << "\n";
                }
                break;
            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, titleName);

                for (const auto &title : titles) {
                    if (title == titleName) {
                        int index = &title - &titles[0];
                        if (status[index]) {
                            status[index] = false;
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
                getline(cin, titleName);

                for (const auto &title : titles) {
                    if (title == titleName) {
                        int index = &title - &titles[0];
                        if (!status[index]) {
                            status[index] = true;
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
                cout << "Invalid selection.\n";
        }

        do {
            cout << "Do you want to perform another operation? (Y/N): ";
            cin >> continueSelection;
        } while (continueSelection != 'Y' && continueSelection != 'N' && continueSelection != 'y' && continueSelection != 'n');

    } while (continueSelection == 'Y' || continueSelection == 'y');

    cout << "Goodbye!";
    return 0;
}
