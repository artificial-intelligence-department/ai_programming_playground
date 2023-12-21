#include <iostream>
#include <string>
using namespace std;

int main() {
    string books[4] = {"Kaidash family", "Kobzar", "Tom Sawyer", "Zakhar Berkut"};
    int available_books[4] = {1, 1, 1, 1}; 
    string end;

    do {
        int task;
        cout << "Меню" << endl;
        cout << "1. Список книг" << endl;
        cout << "2. Взяти книгу" << endl;
        cout << "3. Повернути книгу" << endl;
        cout << "4. Вийти" << endl;
        cout << "Виберіть дію (1, 2, 3, 4): ";
        cin >> task;

        switch (task) {
            case 1: {
                for (int i = 0; i < 4; i++) {
                    cout << "\"" << books[i] << "\" ";
                }
                break;
            }
            case 2: {
                string bookname;
                cout << "Введіть назву: ";
                cin >> bookname;
                bool book_found = false;
                for (int i = 0; i < 4; i++) {
                    if (bookname == books[i]) {
                        if (available_books[i] == 1) {
                            available_books[i] = 0; 
                            cout << "Ви взяли книгу ";
                        } else {
                            cout << "Книга вже взята";
                        }
                        book_found = true;
                        break;
                    }
                }
                if (!book_found) {
                    cout << "Книга не знайдена";
                }
                break;
            }
            case 3: {
                string bookname;
                cout << "Введіть назву книги: ";
                cin >> bookname;
                bool book_found = false;
                for (int i = 0; i < 4; i++) {
                    if (bookname == books[i]) {
                        if (available_books[i] == 0) {
                            available_books[i] = 1; 
                            cout << "Книга повернута";
                        } else {
                            cout << "Книгу ніхто не брав";
                        }
                        book_found = true;
                        break;
                    }
                }
                if (!book_found) {
                    cout << "Книга не знайдена";
                }
                break;
            }
            case 4: {
                cout << "Ви вийшли";
                end = "N";
                break;
            }
            default: {
                cout << "Попробуйте знову";
                break;
            }
        }

        cout << "\nВи хочете зробити щось інше? (Y/N): ";
        cin >> end;
    } while (end == "Y");

    return 0;
}
