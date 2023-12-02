#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> books = {"HarryPotter", "Moriarty the patriot", "Sherlock Holmes", "1984", "Murder on the Orient Express"};
    vector<bool> available = {true, true, true, true, true};//2 вектор, вказуємо на булеві вирази, що книжки наразі доступні

    int usersChoice;  //змінна для збереження вибору опції, яку введе користувач
    string name; //змінна для збереження імені (або іншої інформації), яку користувач може ввести.
while (true){
    menu: //задана точка, до якої ми повертаємось кожен раз
    cout << "\n";
    cout << "\tLibrary Managment\n";
    cout << "\tMenu\n";
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    
    cout << "\nWhat you want to do? ";
    cin >> usersChoice;

    switch(usersChoice) {
        case 1:
            for (int i = 0; i < books.size(); i++) {
                cout << i + 1 << "." << books[i] << (available[i] ? "(Available)" : "(Borrowed)") << "\n";
            }
             goto menu;
        case 2:
            cin.ignore();
            cout << "Enter a book name you would like to borrow: ";
            getline(cin, name);

            for (const auto &book : books) {//:-для усіх елементів 
                //auto дозволяє компілятору автоматично визначити тип даних замість того, щоб явно вказували його.
                if (book == name) {
                    int id = &book - &books[0];// посилання на наші книжки-посилання посилання на перший елемент = номер заданого елемента
                    //по-гумному: адресна арифметика для визначення різниці між адресою поточної книги &book і адресою першої книги у векторі &books[0]. Це дає вам відносний індекс у векторі books.
                    if (available[id]) {
                        available[id] = false;
                        cout << "You borrowed the book successfully!\n";
                        goto menu;
                    } else {
                        cout << "Sorry, book is already borrowed ^_^\n";
                       
                    }
                }
            }
            break;
        case 3:
            cin.ignore();
            cout << "Enter the book name you would like to return: ";
            getline(cin, name);

            for (const auto &book : books) {
                if (book == name) {
                    int id = &book - &books[0];
                    if (!available[id]) {
                        available[id] = true;
                        cout << "You returned the book successfully!\n";
                        goto menu;
                    } else {
                        cout << "Book wasn't borrowed ^_^\n";
                        goto menu;
                    }
                }
            }
            break;
        case 4:
            cout << "See you soon!";
            return 0;
        default:
            cout << "Invalid choice.\n";
            goto menu;
    }
}
}






