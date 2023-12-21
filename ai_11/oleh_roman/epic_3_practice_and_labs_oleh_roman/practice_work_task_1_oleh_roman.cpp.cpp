#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> available = {1, 1, 1, 1};
    int choice;
    string Name;
    string continue_or_no;

    do {
        cout << "Menu:\n"
             << "1. List all books\n"
             << "2. Borrow a book\n"
             << "3. Return a book\n"
             << "4. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < books.size(); i++) {
                    cout << books[i] << ": " << (available[i] ? "Available" : "Borrowed") << endl;
                }
                break;
            case 2:
                cin.ignore();
                cout << "Enter book name to borrow: ";
                getline(cin, Name);
                for (string &book : books) {
                    if (book == Name) {
                        int index = &book - &books[0];
                        if (available[index]) {
                            available[index] = 0;
                            cout << "You take the book\n";
                            break;
                        } else {
                            cout << "This book is borrowed\n";
                            break;
                        }
                    }
                }
                break;
            case 3:
                cin.ignore();
                cout << "Enter book name to return: ";
                getline(cin, Name);
                for (string &book : books) {
                    if (book == Name) {
                        int index = &book - &books[0];
                        if (!available[index]) {
                            available[index] = 1;
                            cout << "You successfully return the book\n";
                            break;
                        } else {
                            cout << "You didn't borrow this book\n";
                            break;
                        }
                    }
                }
                break;
            case 4:
                cout << "Goodbye) See you later";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }

        cout << "Do you want to chose another operation?(Yes/No):";
        cin >> continue_or_no;
        if (continue_or_no == "No"){
            cout << "Goodbye) See you later";
            return 0;
        }
    } while (continue_or_no == "Yes");
}
