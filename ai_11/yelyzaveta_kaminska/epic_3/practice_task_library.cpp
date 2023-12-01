#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

int main() {
    vector<string> books = {"Poppy war", "Death on the Nile", "The school of Good and Evil", "Lunastry"};
    vector<bool> available = {true, true, true, true};
    int choice;
    string bookName;

    while (true) {
        cout << "Library\n";
        cout << "1. List all books\n";
        cout << "2. I want to borrow a book\n";
        cout << "3. I want to return a book\n";
        cout << "4. Exit\n";
        cout << "Please, enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < books.size(); i++) {
                    cout << i + 1 << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << "\n";
                }
                break;
            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, bookName);

                for (int i = 0; i < books.size(); i++) {
                    if (books[i] == bookName) {
                        if (available[i]) {
                            available[i] = false;
                            cout << "You borrowed a book successfully!\n";
                        } else {
                            cout << "Book is already borrowed(.\n";
                        }
                        break;
                    }
                    if (i == books.size() - 1) {
                        cout << "Oops, I dont know this book.\n";
                    }
                }
                break;
            case 3:
                cin.ignore();
                cout << "Enter book name to return: ";
                getline(cin, bookName);

                for (int i = 0; i < books.size(); i++) {
                    if (books[i] == bookName) {
                        if (!available[i]) {
                            available[i] = true;
                            cout << "You returned a book successfully!\n";
                        } else {
                            cout << "Book wasn't returned(.\n";
                        }
                        break;
                    }
                    if (i == books.size() - 1) {
                        cout << "Oops, I dont know this book.\n";
                    }
                }
                break;
            case 4:
                cout << "Goodbye, have a nice day!";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }

        char continue_choice;
        do {
            cout << "You want to try again?) (Y/N): ";
            cin >> continue_choice;
        } while (continue_choice != 'Y' && continue_choice != 'N' && continue_choice != 'y' && continue_choice != 'n');

        if (continue_choice == 'N' || continue_choice == 'n') {
            cout << "Goodbye, have a nice day!)";
            break;
        }
    }

    return 0;
}
