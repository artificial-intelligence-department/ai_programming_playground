

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> book = {"The Night in Lisbon", "Misery", "The Great Gatsby ", "Little Women"}; // Список назв книг
    vector<bool> availability = {true, true, true, true}; // Список доступності книг

    char choice;
    do {
        cout << "Menu:" << endl
         << "1. List all books" << endl
          << "2. Take the book" << endl
         << "3. Return the book" << endl
          << "4. Exit" << endl
          << "Select an option: "<<endl;
        cin >> choice;

        switch (choice) {
            case '1': // Перерахувати всі книги
                cout << "list all books" << endl;
                for (const auto& title : book) { 
                    cout << title << endl;
                }
                break;
            case '2': { // Взяти книгу
                cout << "Choose a book by number: " << endl;
                for (int i = 0; i < book.size(); ++i) {
                    cout << i + 1 << ". " << book[i] << " - ";
                    cout << (availability[i] ? "available" : "unavailable") << endl;  
                }
                int bookNumber;
                cout << "book number: ";
                cin >> bookNumber;

                if (bookNumber >= 1 && bookNumber <= book.size()) {
                    if (availability[bookNumber - 1]) {
                        availability[bookNumber - 1] = false;
                        cout << "you took a book '" << book[bookNumber - 1] << "'" << endl;
                    } else {
                        cout << "this book has already been token" << endl;
                    }
                } else {
                    cout << "invalid book number" << endl;
                    goto invalidChoice;
                }
                break;
            }
            case '3': { // Повернути книгу
                cout << "Choose a book by number: " << endl;
                for (int i = 0; i < book.size(); ++i) {
                    cout << i + 1 << ". " << book[i] << " - ";
                    cout << (availability[i] ? "available" : "unavailable") << endl;
                }
                int bookNumber;
                cout << "book number: ";
                cin >> bookNumber;

                if (bookNumber >= 1 && bookNumber <= book.size()) {
                    if (!availability[bookNumber - 1]) {     
                        availability[bookNumber - 1] = true;
                        cout << "you returned a book '" << book[bookNumber - 1] << "'" << endl;
                    } else {
                        cout << "This book is already here" << endl;
                    }
                } else {
                    cout << "invalid book number" << endl;
                    goto invalidChoice;
                }
                break;
            }
            case '4': // Вийти
                cout << "have a good day!" << endl;
                break;
            default:
                invalidChoice:
                cout << "invalid choice. Try again!" << endl;
                break;
        }
    } while (choice != '4');

    return 0;

}