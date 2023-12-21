#include <iostream>
#include <vector>
#include <string>
using namespace std;
void listbooks(const vector<string>& books, const vector<bool>& availability) {
    cout << "Books  in Library: \n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << i + 1 << ". " << books[i];
        if (availability[i]) {
            cout << " (Available)\n";
        } else {
            cout << " (Taken)\n";
        }
    }
}
int main() {
    vector<string> books = {"A Tale of Two Cities", "The Little Prince", "Harry Potter and the Philosopher's Stone", "And Then There Were None", "Dream of the Red Chamber", "The Hobbit", "Black Beauty"};
    vector<bool> availability = {true, true, true, true, true, true, true};
    int choose;
    while (true) {
        cout << "\nMain Menu:\n";
         cout << "1. Borrow a book\n";
         cout << "2. Return the book\n";
         cout << "3. List all books\n";
         cout << "4. Exit\n";
         cout << "Your choice: ";
         cin >> choose;
        switch (choose) {
            case 1:  
                listbooks(books, availability);
                cout << "Choose the book: ";
                int Choice;
                cin >> Choice;
                if (Choice >= 1 && Choice <= books.size() && availability[Choice - 1]) {
                    cout << "You borrowed a book: " << books[Choice - 1] << endl;
                    availability[Choice - 1] = false;
                } else {
                    cout << "The book is already in selection or the wrong number was entered.\n";
                }
                break;
            case 2:  
                listbooks(books, availability);
                cout << "Select the book number to return: ";
                int returnChoice;
                cin >> returnChoice;

                if (returnChoice >= 1 && returnChoice <= books.size() && !availability[returnChoice - 1]) {
                    cout << "You returned the book: " << books[returnChoice - 1] << endl;
                    availability[returnChoice - 1] = true;
                } else {
                    cout << "The book is already in selection or the wrong number was entered.\n";
                }
                break;
            case 3:  
                listbooks(books, availability);
                break;
            case 4:  
            default:
                cout << "Wrong choice. Try again.\n";
                break;
        }
    }
    return 0;
}
