#include <iostream>
#include <string>

const int MaxBook = 4;

using namespace std;

int listofBooks(const string books[], const bool availability[]) 
{
    cout << "Бібліотека\n";
    int availablebookamount = 0;

    for (int i = 0; i < MaxBook; ++i) 
    {
        cout << i + 1 << ". " << books[i] << " - " << (availability[i] ? "Є в наявності" : "Нема в наявності") << "\n";
        if (availability[i]) 
        {
            availablebookamount++;
        }
    }

    return availablebookamount;
}

int main() 
{
    string bookTitles[MaxBook] = {"СУТІНКИ", "АЛХІМІК", "ЩОДЕННИК АННИ ФРАНК", "БІБЛІЯ"};
    bool availability[MaxBook] = {true, true, true, true};

    while (true) 
    {
        cout << "1. Набір книг\n";
        cout << "2. Взяти книгу \n";
        cout << "3. Повернути книгу\n";
        cout << "4. Вихід\n";

        int choice;
        cout << "Введіть свій вибір: ";
        cin >> choice;

        if (choice == 1) 
        {
            if (listofBooks(bookTitles, availability) == 0) 
            {
                cout << "Немає книг(\n";
            }
        } 
        else if (choice == 2 || choice == 3) 
        {
            int bookNumber;
            cout << "Введіть число книги ";
            cin >> bookNumber;

            if (bookNumber > 0 && bookNumber <= MaxBook) 
            {
                if ((choice == 2 && availability[bookNumber - 1]) || (choice == 3 && !availability[bookNumber - 1])) 
                {
                    cout << "Ви " << (choice == 2 ? "взяли" : "повернули") << " книгу\n";
                    availability[bookNumber - 1] = (choice == 2 ? false : true);
                } 
                else 
                {
                    cout << "Неправильна операціяю. Книгу вже " << (choice == 2 ? "взяли" : "в бібліотеці") << ".\n";
                }
            } 
            else 
            {
                cout << "Неправильне число книги\n";
            }
        } 
        else if (choice == 4) 
        {
            cout << "Вихід з меню\n";
            break;
        }
        else 
        {
            cout << "Неправильне число. Спробуйте знову\n";
        }
    }

    return 0;
}
