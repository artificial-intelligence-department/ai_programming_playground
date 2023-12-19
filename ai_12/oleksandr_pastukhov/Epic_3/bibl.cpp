#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = {"HarryPotter", "The Hobbit", "The Fight Club", "1984"};
    vector<bool> condition = {true, true, true, true};

    int choice;
    string name;
    
    // Declare the variables outside the switch block
    bool bookWasntFound = true;
    bool bookWasntFoundReturn = true;

    while (true) {
        menu:
            cout << "\tMenu" << endl;
            cout << "1. List all books" << endl;
            cout << "2. Borrow a book" << endl;
            cout << "3. Return a book" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter your choice" << endl;
            cin >> choice;

            switch (choice) {
                case 1:
                    for (int count = 0; count < books.size(); count++) {
                        cout << count + 1 << '.' << books[count] << (condition[count] ? " available" : " not available") << endl;
                    }
                    goto menu;

                case 2:
                    cout << "Enter name of your book" << endl;
                    cin >> name;

                    bookWasntFound = true;

                    for (int i = 0; i < books.size(); i++) {
                        if (name == books[i]) {
                            if (condition[i]) {
                                cout << "You borrowed the book successfully" << endl;
                                condition[i] = false;
                                bookWasntFound = false;
                            } else {
                                cout << "Unfortunately your book isn't available" << endl;
                            }
                        }
                    }

                    if (bookWasntFound) {
                        cout << "You entered the wrong name" << endl;
                    }
                    goto menu;

                case 3:
                    cout << "Enter name of your book" << endl;
                    cin >> name;

                    bookWasntFoundReturn = true;

                    for (int i = 0; i < books.size(); i++) {
                        if (name == books[i]) {
                            if (!condition[i]) {
                                cout << "You returned the book successfully" << endl;
                                condition[i] = true;
                                bookWasntFoundReturn = false;
                            } else {
                                cout << "Unfortunately your book isn't taken" << endl;
                            }
                        }
                    }

                    if (bookWasntFoundReturn) {
                        cout << "You entered the wrong book name" << endl;
                    }
                    goto menu;

                case 4:
                    cout << "Bye-bye" << endl;
                    return 0;
            }
    }

    return 0;
}
