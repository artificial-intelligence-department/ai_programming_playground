#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
public:
    string title;
    string author;

    // ініціалізація книги
    Book(const string& t, const string& a) : title(t), author(a) {}

    // оператор виведення книги
    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title: " << book.title << "\nAuthor: " << book.author << "\n";
        return os;
    }
};

// Функція для вибору книжки зі списку
Book chooseBook(const vector<Book>& books, int index) {
    if (index >= 0 && index < books.size()) {
        return books[index];
    } else {
        // Повертаємо порожню книгу у випадку не правильного індексу
        return Book("Invalid Book", "Invalid Author");
    }
}

int main() {
    // Створюємо список книг
    vector<Book> bookList;
    bookList.push_back(Book("Book 1", "Author 1"));
    bookList.push_back(Book("Book 2", "Author 2"));
    bookList.push_back(Book("Book 3", "Author 3"));

    // Виводимо список книг для вибору
    cout << "Choose a book from the list:\n";
    for (int i = 0; i < bookList.size(); ++i) {
        cout << i + 1 << ". " << bookList[i].title << "\n";
    }

    // Введення вибору користувача
    int userChoice;
    cout << "Enter the number of the book you want to choose: ";
    cin >> userChoice;

    // Виведення книги
    Book selectedBook = chooseBook(bookList, userChoice - 1);
    cout << "\nYou have chosen:\n" << selectedBook;

    return 0;
}