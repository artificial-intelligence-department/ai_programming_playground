#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> books;
vector<bool> booksAvailability;

int booksCount() {
    cout << "The books amount is: " + to_string(books.size()) << endl;
    return books.size();
}

int addBook(string bookToAdd) {
    books.push_back(bookToAdd);
    booksAvailability.push_back(true);
    cout << "You successfully added book " + bookToAdd << endl;
    return 1;
}

int takeBook(string bookToTake) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == bookToTake) {
            booksAvailability[i] = false;
            cout << "You successfully took book " + bookToTake << endl;
            return 1;
        }
    }
    cout << "There's no book like this available" << endl;
    return 0;
}

int returnBook(string bookToReturn) {
    for (int i = 0; i < books.size(); i++) {
        if (books[i] == bookToReturn) {
            if (not booksAvailability[i]) {
                booksAvailability[i] = true;
                cout << "You successfully returned a book " + bookToReturn << endl;
                return 1;
            }
        }
    }
    cout << "You don't need to return this book" << endl;
    return 0;
}

int showBooks() {
    cout << "Available books are: " << endl;
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < books.size(); i++) {
        if (booksAvailability[i]) {
            cout << books[i] + ": Available" << endl;
        }
        else {
            cout << books[i] + ": Not available"<< endl;
        }
    }
    cout << "--------------------------------------" << endl;
    return 1;
}

int checkActions(const string Action) {
    string indepAction;
    for (char c: Action) {
        indepAction += tolower(c);
    }
    if (indepAction == "count") {
        return booksCount();
    }
    else if (indepAction == "add") {
        string book;
        cout << "Enter a name of book you wanna add: ";
        cin >> book;

        return addBook(book);
    }
    else if (indepAction == "take") {
        string book;
        cout << "Enter a name of book you wanna take: ";
        cin >> book;

        return takeBook(book);
    }
    else if (indepAction == "return") {
        string book;
        cout << "Enter a name of book you wanna return: ";
        cin >> book;

        return returnBook(book);
    }
    else if (indepAction == "library") {
        return showBooks();
    }
    else {
        cout << "Invalid action" << endl;
        return 0;
    }
}

int main() {
    string action;

    while (true) {
        cout << "Enter you action: ";
        cin >> action;

        if (action == "Exit" || action == "exit") {
            break;
        }

        checkActions(action);
    }
}

