#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string books[4] = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    bool available[4]= {true, true, true, true};

    int option;
    bool condition = true;
    Menu:
    while (true) {
        cout << "1. List of all books" << endl;
        cout << "2. Borrow" << endl;
        cout << "3. Return" << endl;
        cout << "4. Exit" << endl;
        cout << "What do you want?" << endl;;
        cin >> option;
        int num;

        if (option==1) {
            cout << "List of all books:" << endl;
            for (int i=0; i<4; i++) {
                cout << i+1<< ". " << books[i] << " (" << (available[i] ? "Available" : "Borrowed") << ")" << endl;
            }
        } else if (option==2) {
            cout << "Which book do you want to borrow?" << endl;;
            cin >> num;

            if (num>=1 && num<=4) {
                if (available[num-1]) {
                    available[num-1] = false;
                    cout << "You've borrowed " << books[num-1] << endl;
                } else {
                    cout << "This book is unavailable." << endl;
                }
            } else {
                cout << "Invalid option." << endl;
                goto Menu;
            }
        } else if (option==3) {
            cout << "Which book do you want to return?" << endl;;
            cin >> num;

            if (num>=1 && num<=4) {
                if (available[num-1]) {
                    available[num-1] = true;
                    cout << "You've returned " << books[num-1] << endl;
                } else {
                    cout << "This book is available." << endl;
                }
            } else {
                cout << "Invalid option." << endl;
                goto Menu;
            }
        } else if (option==4) {
            condition=false;
        } else {
            cout << "Invalid option." << endl;
            goto Menu;
        }

         cout << "If you want to return to the main page, press 1, otherwise press 0 ";
         cin >> condition;
         goto Menu;
    }

    return 0;
}


