#include <iostream>
#include <string>

int main()
{
    using namespace std;

    const int Long = 3; // розмір масиву

    string lib[Long] = {"Біблія", "1984", "ГДЗ_Математика"}; //основиний масив
    bool available[Long] = {true, true, true}; //масив що відповідає за наявності книг

    cout << "Ласкаво просимо до бібліотеки. Тут ви зможете знайти великий вибір книг\n";

    bool repeat = true;

    while (repeat)
    {
        cout << "Що ви хочете зробити (введіть номер)\n";
        cout << "1) Переглянути список книг\n";
        cout << "2) Взяти книгу з бібліотеки\n";
        cout << "3) Повернути книгу\n";
        cout << "4) Вийти з програми\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        //-------Переглянути список книг-------//
        case 1:
            cout << "У нас є наступні книги:" << endl;
            for (int i = 0; i < Long; ++i)
            {
                cout << (available[i] ? "Доступна - " : "Недоступна - ") << lib[i] << endl;
            }
            break;
        //-------Взяти книгу з бібліотеки-------//
        case 2:
            cout << "У нас є наступні книги:\n";
            for (int i = 0; i < Long; ++i)
            {
                if (available[i])
                {
                    cout << i + 1 << " " << lib[i] << endl;
                }
            }

            cout << "Яку книгу ви хочете взяти?: ";
            int number;
            cin >> number;
            --number;

            if (number >= 0 && number < Long && available[number])
            {
                cout << "Вітаємо! Ви взяли книгу " << lib[number] << endl;
                available[number] = false; // false для недоступної
            }
            else
            {
                cout << "Неправильний вибір або книга не доступна\n";
            }
            break;
        //-------Повернути книгу-------//
        case 3:
            cout << "Яку книгу ви хочете повернути?\n";
            for (int i = 0; i < Long; ++i)
            {
                if (!available[i])
                {
                    cout << i + 1 << ") " << lib[i] << endl;
                }
            }

            cout << "Введіть номер книги для повернення: ";
            int ret;
            cin >> ret;
            --ret;

            if (ret >= 0 && ret < Long && !available[ret])
            {
                cout << "Вітаємо! Ви повернули книгу " << lib[ret] << endl;
                available[ret] = true; // true для доступної
            }
            else
            {
                cout << "Неправильний вибір або книга не взята\n";
            }
            break;
        //-------Вихід з програми-------//
        case 4:
            cout << "Дякуємо за відвідування нашої бібліотеки!\n";
            repeat = false;
            break;
        //-------Введення-лабуди-------//
        default:
            cout << "Неправильний вибір\n";
            break;
        }

        char ans;
        cout << "Чи хочете продовжити? (no) ";
        cin >> ans;

        if (ans == 'n' || ans == 'N')
        {
            repeat = false;
        }
        else
        {
            repeat = true;
        }
    }

    return 0;
}