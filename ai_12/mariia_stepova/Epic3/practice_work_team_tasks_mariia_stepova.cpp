#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    bool available;
};

vector<Book> library = {
    {"Гаррі Поттер і філософський камінь", true},
    {"Фантастичні звірі і де їх шукати", true},
    {"Аліса в Країні Див. Аліса в Задзеркаллі", true},
    {"Пригоди Тома Сойєра", true},
    {"Мандри Ґуллівера", true}
};

void displayBooks() {
    cout << "Книги в наявності в бібліотеці:\n";
    for (const auto& book : library) {
        cout << "- " << book.title << " (в наявності: " << (book.available ? "так" : "ні") << ")\n";
    }
}

bool borrowBook(const string& bookTitle) {
    for (auto& book : library) {
        if (book.title == bookTitle && book.available) {
            book.available = false;
            cout << "Ви позичили книгу: " << book.title << ". Насолоджуйтесь читанням!\n";
            return true;
        }
    }
    cout << "Вибачте, книга " << bookTitle << " або недоступна, або не існує в бібліотеці.\n";
    return false;
}

bool returnBook(const string& bookTitle) {
    for (auto& book : library) {
        if (book.title == bookTitle && !book.available) {
            book.available = true;
            cout << "Дякуємо за повернення книги: " << book.title << ".\n";
            return true;
        }
    }
    cout << "Вибачте, " << bookTitle << " з цієї бібліотеки не було позичено.\n";
    return false;
}

int main() {
    char choice;
    string bookTitle;

    do {
        cout << "\nМеню:\n";
        cout << "1. Перерахувати всі книги\n";
        cout << "2. Позичити книжку\n";
        cout << "3. Повернути книжку\n";
        cout << "4. Вийти\n";
        cout << "Введіть свій вибір: ";
        cin >> choice;

        switch (choice) {
            case '1':
                displayBooks();
                break;
            case '2':
                do {
                    cout << "Введіть назву книги, яку ви хочете взяти: ";
                    cin.ignore(); 
                    getline(cin, bookTitle);
                } while (!borrowBook(bookTitle));
                break;
            case '3':
                do {
                    cout << "Введіть назву книги, яку ви хочете повернути: ";
                    cin.ignore(); 
                    getline(cin, bookTitle);
                } while (!returnBook(bookTitle));
                break;
            case '4':
                cout << "Вихід з програми. До побачення!\n";
                break;
            default:
                cout << "Невірний вибір. Введіть правильний варіант.\n";
                break;
        }
    } while (choice != '4');

    return 0;
}
