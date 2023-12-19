#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> books = {"Book 1", "Book 2", "Book 3"}; // Масив з назвами книг
    vector<bool> availability = {true, true, true}; // Масив зі станом доступності кожної книги

    while (true) {
        cout << "1. List all books" << endl;
        cout << "2. Take a book" << endl;
        cout << "3.Return the book" << endl;
        cout << "4. Go out" << endl;
        cout << "Select an option: ";
        int option;
        cin >> option;
        //1. Перерахувати всі книги
        //2. Візьміть книгу
        //3.Повернути книгу
        //4. Вийти

        switch (option) {
            case 1: // Перерахувати всі книги
                for (string book : books) {
                    cout << book << endl;
                }
                break;

            case 2: // Взяти книгу
                cout << "Choose a book number: ";
                int bookNumber;
                cin >> bookNumber;

                if (bookNumber >= 1 && bookNumber <= books.size()) {
                    if (availability[bookNumber - 1]) {
                        availability[bookNumber - 1] = false;
                        cout << "You took the book \"" << books[bookNumber - 1] << "\"" << endl;
                    } else {
                        cout << "This book is already taken" << endl;
                    }
                } else {
                    cout << "Invalid book number" << endl;
                }
                break;

            case 3: // Повернути книгу
                cout << "Select a book number: ";
                cin >> bookNumber;

                if (bookNumber >= 1 && bookNumber <= books.size()) {
                    if (!availability[bookNumber - 1]) {
                        availability[bookNumber - 1] = true;
                        cout << "You returned the book \"" << books[bookNumber - 1] << "\"" << endl;
                    } else {
                        cout << "This book has not yet been taken" << endl;
                    }
                } else {
                    cout << "Invalid book number" << endl;
                }
                break;

            case 4: // Вийти
                return 0;

            default: // Невірний вибір опції
                cout << "Incorrect option selection" << endl;
                break;
        }
    }

    return 0;
}