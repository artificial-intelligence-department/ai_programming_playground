#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayBooks(const vector<string> &books, const vector<string> &statuses) {
    cout << "List of books:\n";
    for (size_t i = 0; i < books.size(); ++i) {
        cout << books[i] << " -- " << statuses[i] << "\n";
    }
}

int main() {
    int numBooks, action;

    cout << "Enter the number of books: ";
    cin >> numBooks;

    while (numBooks < 1) {
        cout << "Enter a valid number of books (1 or more): ";
        cin >> numBooks;
    }

    vector<string> books(numBooks);
    vector<string> statuses(numBooks, "Available");

    for (int i = 0; i < numBooks; ++i) {
        cout << "Enter book " << i + 1 << ": ";
        cin >> books[i];
    }

    do {
        cout << "\n1) List of books\n";
        cout << "2) Take a book\n";
        cout << "3) Return a book\n";
        cout << "4) Exit\n\n";
        cout << "Choose your action: ";
        cin >> action;

        switch (action) {
            case 1:
                displayBooks(books, statuses);
                break;
            case 2:
            case 3: {
                cout << "Enter a book: ";
                string inputBook;
                cin >> inputBook;

                bool bookFound = false;
                for (size_t i = 0; i < books.size(); ++i) {
                    if (books[i] == inputBook) {
                        bookFound = true;
                        if (action == 2 && statuses[i] == "Available") {
                            statuses[i] = "Borrowed";
                            cout << "Book " << books[i] << " borrowed successfully.\n";
                        } else if (action == 3 && statuses[i] == "Borrowed") {
                            statuses[i] = "Available";
                            cout << "Book " << books[i] << " returned successfully.\n";
                        } else {
                            cout << "Book not available for the chosen action.\n";
                        }
                        break;
                    }
                }
                if (!bookFound) {
                    cout << "Book not found.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Choose a valid action (1 to 4).\n";
                break;
        }

    } while (action != 4);

    return 0;
}