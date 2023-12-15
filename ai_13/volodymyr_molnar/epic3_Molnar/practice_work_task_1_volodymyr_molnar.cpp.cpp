#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    vector<string> books = { "Book1","Book2","Book3"};
    vector<bool> availability = { true, true, true };
    int choose, borrow, returnIndx;
    bool q = true;
    do {
        cout << "select an operation:\n";
        cout << "1. list all books\n";
        cout << "2. borrow a book\n";
        cout << "3. return a book\n";
        cout << "4. exit\n";
        cout << "your choice: ";
        cin >> choose;
        switch (choose) {
        case 1: 
            cout << "list of all books:\n";
            for (const string& book : books) 
                cout << book << endl;
            break;
        case 2:
            cout << "enter the number of the book you want to borrow: ";
            cin >> borrow;
            if (borrow >= 0 && borrow < books.size() && availability[borrow]) {
                cout << "you borrowed the book: " << books[borrow] << endl;
                availability[borrow] = false;
            }
            else 
                cout << "this book is unavailable or the entered number is incorrect.\n";
            break;
        case 3:
            cout << "enter the number of the book you are returning: ";
            cin >> returnIndx;
            if (returnIndx >= 0 && returnIndx < books.size() && !availability[returnIndx]) {
                cout << "you returned the book: " << books[returnIndx] << endl;
                availability[returnIndx] = true;
            }
            else 
                cout << "this book is unavailable or the entered number is incorrect.\n";
            break;
        case 4:
            q = false;
            break;
        default: 
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        if (q) {
            char continueChoice;
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> continueChoice;
            if (continueChoice != 'y') 
                q = false;
        }
    } while (q);
    return 0;
}
