#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> library;
    library.push_back("Hamlet");
    library.push_back("Matilda");
    library.push_back("Constitution");

    vector<bool> bookPresence;
    bookPresence.push_back(true);
    bookPresence.push_back(true);
    bookPresence.push_back(true);

    cout << "\nWelcome to Vira's library. If you want to exit, type \"exit\".\n\n";
    cout << "I have these books in my library: \n";
    for (int i = 0; i < library.size(); ++i) {
        cout << library[i] << "\n";
    }

    while (true) {
        cout << "\nIf you want to take a book, type \"take\".\nIf you want to return a book, type \"give\".\n";
        string userInput; // userInput = take or give
        cin >> userInput;
        if (userInput == "take") {
            cout << "Type the name of book you want to take\n";
            string wantedBook;
            cin >> wantedBook;
            if (wantedBook == "exit"){
                cout << "Thanks for visiting, goodbye!\n";
                break;
            }

            int bookIndex = -1;

            for (int i = 0; i < library.size(); i++) {
                string currentBook = library[i];
                bool isBookTheSame = (currentBook == wantedBook);
                if (isBookTheSame) {
                    bookIndex = i;
                    break;
                }
            }
            if (bookIndex == -1) {
                cout << "Sorry we don't have this book in our library\n\n";
            }
            else {
                if (bookPresence[bookIndex]) {
                    cout << "There is such book in our library. You can take it\n\n";
                    bookPresence[bookIndex] = false;
                } else {
                    cout << "Sorry this book is currently not available\n\n";
                }
            }

        } else if (userInput == "give") {
            cout << "Type the name of book you want to return\n";
            string givenBook;
            cin >> givenBook;
            if (givenBook == "exit"){
                cout << "Thanks for visiting, goodbye!\n";
                break;
            }

            int bookIndex = -1;

            for (int i = 0; i < library.size(); i++) {
                string currentBook = library[i];
                bool isBookTheSame = (currentBook == givenBook);
                if (isBookTheSame) {
                    bookIndex = i;
                    break;
                }
            }
            if (bookIndex == -1) {
                cout << "Sorry we never had this book in our library\n\n";
            }
            else {
                if (bookPresence[bookIndex]) {
                    cout << "This book is not from our library\n\n";
                } else {
                    cout << "Thanks for returning this book\n\n";
                    bookPresence[bookIndex] = true;
                }
            }
        } else {
            if (userInput == "exit"){
                cout << "Thanks for visiting, goodbye!\n";
                break;
            } else {
                cout << "ERROR. Please provide a valid command\n";
            }
        }
    }
}