#include <iostream>
using namespace std;

string bookTitle[5] = {"book 1", "book 2", "book 3", "book 4", "book 5"};
bool bookState[5] = {true, true, true, true, true,};

void printBookList() {
    cout << "Список всіх книг:" << endl;
    for (int i = 0; i < 5; ++i) {
        if (bookState[i] == true) 
            cout << i + 1 << ") " << bookTitle[i] << " +" << endl;
        else 
            cout << i + 1 << ") " << bookTitle[i] << " -" << endl;
    }
}

void takeBook(int bookNumber) {
    changeSel:
    if (bookNumber >= 1 && bookNumber <= 5) {
        if (bookState[bookNumber - 1] == true) {
            cout << "Ви взяли книгу: " << bookTitle[bookNumber - 1] << endl;
            bookState[bookNumber - 1] = false;
            cout << "бажаєте обрти ще одну книгу? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes")
            {
                cout << "Оберіть книгу за номером: ";
                cin >> bookNumber;
                goto changeSel;
            }
        } else {
            cout << "Книга " << bookTitle[bookNumber - 1] << " вже зайнята, бажаєте обраьт інакшу? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes")
            {
                cout << "Оберіть книгу за номером: ";
                cin >> bookNumber;
                goto changeSel;
            }
        }
    } else {
        cout << "Невірний номер книги, введіть існуючий номер:" << endl;
        cin >> bookNumber;
        goto changeSel;
    }
}

void returnBook(int bookNumber) {
    changeSel:
    if (bookNumber >= 1 && bookNumber <= 5) {
        if (bookState[bookNumber - 1] == false) {
            cout << "Ви повернули книгу: " << bookTitle[bookNumber - 1] << endl;
            bookState[bookNumber - 1] = true;
            cout << "бажаєте повернути ще одну книгу? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes") {
                cout << "Оберіть книгу за номером: ";
                cin >> bookNumber;
                goto changeSel;
            }
        } else {
            cout << "Книга " << bookTitle[bookNumber - 1] << " вже в бібліотеці. Бажаєте вибрати іншу? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes") {
                cout << "Оберіть книгу за номером: ";
                cin >> bookNumber;
                goto changeSel;
            }
        }
    } else {
        cout << "Невірний номер книги, введіть існуючий номер:" << endl;
        cin >> bookNumber;
        goto changeSel;
    }
}

int main() {
    string exit;
    int menu = 0;

    do 
    {
        tryAgain:
            cout << endl;
            cout << "main menu:" << endl;
            cout << "1 - Переглянути всі книги" << endl;
            cout << "2 - Взяти книгу" << endl;
            cout << "3 - Повернути книгу" << endl;
            cout << "0 - Вихід" << endl;

            if (!(cin >> menu)) { //запобіжник від некоректного введення
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Невірний ввід. Будь ласка, введіть число." << endl;
                goto tryAgain;
            }
        switch (menu) {
        case 0:
            return 0;

        case 1:
            printBookList();
            break;
        case 2:
            {
            cout << "бажаєте переглянути каталог книг? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes") {
                printBookList();
            }
            cout << "Оберіть книгу за номером: ";
            int selectedBook;
            cin >> selectedBook;
            takeBook(selectedBook);
            break;
            }
        case 3:
            {
            cout << "Бажаєте переглянути каталог книг? (yes/no)" << endl;
            string ask = "";
            cin >> ask;
            if (ask == "yes") {
                printBookList();
            }
            cout << "Оберіть книгу за номером: ";
            int returnBookNumber;
            cin >> returnBookNumber;
            returnBook(returnBookNumber);
            break;
            }
        default:
            cout << "неіснуюча операція, введіть номер існуючої операції." << endl;
            goto tryAgain;
        }

        cout << "чи бажаєте виконати ще одну операцію? (yes / no)" << endl;
        cin >> exit;
    } while (exit == "yes");
}
