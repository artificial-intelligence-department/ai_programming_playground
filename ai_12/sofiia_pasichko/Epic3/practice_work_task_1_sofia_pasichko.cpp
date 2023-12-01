#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string books[4] = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    bool available[4] = {true, true, true, true};

    int option;
    bool condition = true;

    while (condition) {
        cout << "1. List of all books" << endl;
        cout << "2. Borrow" << endl;
        cout << "3. Return" << endl;
        cout << "4. Exit" << endl;
        cout << "What do you want?" << endl;
        cin >> option;
        int num;

        switch (option) {
            case 1:
                cout << "List of all books:" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << i + 1 << ". " << books[i] << " (" << (available[i] ? "Available" : "Borrowed") << ")" << endl;
                }
                break;

            case 2:
                cout << "Which book do you want to borrow?" << endl;
                cin >> num;
                if (available[num-1]=true) {
                    available[num-1]=false;
                    cout << "You've borrowed " << books[num-1] << endl;
                } else {
                    cout << "This book is unavailable." << endl;
                }
                break;

            case 3:
                cout << "Which book do you want to return?" << endl;
                cin >> num;
                if (available[num-1]=false) {
                    available[num-1]=true;
                    cout << "You've returned " << books[num-1] << endl;
                } else {
                cout << "This book is available." << endl;
                }
                break;

            case 4:
                condition = false;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

        if (condition) {
            cout << "If you want to return to the main page, press 1, otherwise press 0: ";
            cin >> condition;
        }
    }

    

    return 0;
}