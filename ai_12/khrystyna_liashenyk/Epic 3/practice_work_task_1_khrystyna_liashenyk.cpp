#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    vector<bool> available(4, true);

    int want;
    bool cont = true;
    menu:
    while (cont) {
        cout << "1. List of all books" << endl;
        cout << "2. Borrow" << endl;
        cout << "3. Return" << endl;
        cout << "4. Exit" << endl;
        cout << "What do you want: ";
        cin >> want;
        int number;

        if (want == 1) {
            cout << "List of all books:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << i+1<< ". " << books[i] << " (" << (available[i] ? "Available" : "Borrowed") << ")" << endl;
            }
        } else if (want == 2) {
            cout << "Which book do you want to borrow (number of the book): ";
            cin >> number;

            if (number >= 1 && number <= 4) {
                if (available[number - 1]) {
                    available[number - 1] = false;
                    cout << "You've borrowed: " << books[number - 1] << "" << endl;
                } else {
                    cout << "This book is borrowed." << endl;
                }
            } else {
                cout << "Incorrect." << endl;
                goto menu;
            }
        } else if (want == 3) {
            cout << "Which book do you want to return (number of the book): ";
            cin >> number;

            if (number >= 1 && number <= 4) {
                if (!available[number - 1]) {
                    available[number - 1] = true;
                    cout << "You've returned: " << books[number - 1] << "" << endl;
                } else {
                    cout << "This book is available." << endl;
                }
            } else {
                cout << "Incorrect." << endl;
                goto menu;
            }
        } else if (want == 4) {
            cont = false;
        } else {
            cout << "Incorrect." << endl;
            goto menu;
        }
         cout << "If you want to return to the main page, press 1, otherwise press 0 ";
        cin >> cont;
         goto menu;
    }

    return 0;
}
