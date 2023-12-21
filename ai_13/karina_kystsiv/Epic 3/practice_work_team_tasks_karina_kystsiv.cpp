#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = {"Hunger Games", "The Lord of the Rings", "Da Vinci Code", "Murder on the Orient Express"};
    vector<bool> available = {true, true, true, true};
    int choice;
    string bookName; 
 cout << "Welcome to the library!\n";
menu:
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Print your choice: ";

    string choiceStr;
    getline(cin, choiceStr);

    try {
        choice = stoi(choiceStr);
    } catch (const invalid_argument& e) {
        goto menu;
    }

    switch (choice) {
        case 1:
            for (int i = 0; i < books.size(); i++) {
                cout << i + 1 << ". " << books[i] << (available[i] ? "(Available)" : "(Borrowed)") << "\n";
            }
            break;
        case 2:
            cout << "Enter book name to borrow: ";
            getline(cin, bookName);
            for (int i = 0; i < books.size(); i++) {
                if (books[i] == bookName) {
                    if (available[i]) {
                        available[i] = false;
                        cout << "Enter book name to borrow:\n";
                    } else {
                        cout << "Book borrowed successfully!\n";
                    }
                    break;
                }
            }
            break;
        case 3:
            cout << "Enter book name to return:";
            getline(cin, bookName);
            for (int i = 0; i < books.size(); i++) {
                if (books[i] == bookName) {
                    if (!available[i]) {
                        available[i] = true;
                        cout << "Book returned successfully!\n";
                    } else {
                        cout << "Book wasn't borrowed\n";
                    }
                    break;
                }
            }
            break;
        case 4:
            cout << "Goodbye!\n";
            return 0;
    default:
            cout << "Wrong choice\n";
            goto menu;
    }
    char continueChoice;
    do {
        cout << " Do you want to perform another operation? (Y/N):";
        cin >> continueChoice;
    } while (continueChoice != 'Y' && continueChoice != 'y' && continueChoice != 'N' && continueChoice != 'n');

    if (continueChoice == 'Y' || continueChoice == 'y') {
        goto menu;
    } else {
        cout << "Have a nice day!!\n";
        return 0;
    }
}
