#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> books = {"HarryPotter", "Warriors", "FollowingTheLight", "ThePerfectStranger"};
    vector<bool> available = {true, true, true, true};

    int option;
    string name;

    menu:
    cout << "\tMenu\n";
    cout << "1. List all books in the library\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";

    continuation:
    cout << "\nWhat would you like to do? ";
    cin >> option;

    switch(option) {
        case 1:
            for (int i = 0; i < books.size(); i++) {
                cout << i + 1 << "." << books[i] << (available[i] ? "(Available)" : "(Borrowed)") << "\n";
            }
            goto continuation;
        case 2:
            cin.ignore();
            cout << "Enter a book name you would like to borrow: ";
            getline(cin, name);

            for (const auto &book : books) {
                if (book == name) {
                    int id = &book - &books[0];
                    if (available[id]) {
                        available[id] = false;
                        cout << "You borrowed the book successfully!\n";
                        goto continuation;
                    } else {
                        cout << "Sorry, but the book is already borrowed.\n";
                        goto continuation;
                    }
                }
            }
            break;
        case 3:
            cin.ignore();
            cout << "Enter a book name you would like to return: ";
            getline(cin, name);

            for (const auto &book : books) {
                if (book == name) {
                    int id = &book - &books[0];
                    if (!available[id]) {
                        available[id] = true;
                        cout << "You returned the book successfully!\n";
                        goto continuation;
                    } else {
                        cout << "Sorry, but the book wasn't borrowed.\n";
                        goto continuation;
                    }
                }
            }
            goto continuation;
            break;
        case 4:
            cout << "See you soon!";
            return 0;
        default:
            cout << "Invalid choice.\n";
            goto menu;
    }
}
