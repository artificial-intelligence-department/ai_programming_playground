#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{
    int N, choice;
    cout << "Вкажіть кількість книг: ";
    cin >> N;

    while (N < 1) 
    {
        cout << "Кількість книг повинна бути більшою за нуль: ";
        cin >> N;
    }

    vector <string> books (N);
    vector <string> status (N, "В наявності");

    for (int i = 0; i < N; i++) 
    {
        cout << "Вкажіть назву " << i + 1 << " книги: ";
        cin >> books[i];
    }

    do 
    {
        cout << "\n1) Список книг\n";
        cout << "2) Позичити книгу\n";
        cout << "3) Повернути книгу\n";
        cout << "4) Вихід\n\n";
        cout << "Вкажіть дію: ";
        cin >> choice;
        while (choice < 1 || choice > 4) 
        {
            cout << "Дія повинна бути 1, 2, 3, 4: ";
            cin >> choice;
        }

        if (choice == 1) 
        {
            for (int i = 0; i < N; i++) 
            {
                cout << books[i] << " -- " << status[i] << "\n";
            }
        } 
        else if (choice == 2 || choice == 3) 
        {
            cout << "Введіть назву книгу: ";
            string entered_book;
            cin >> entered_book;

            for (int i = 0; i < N; i++) 
            {
                if (books[i] == entered_book) 
                {
                    if (choice == 2 && status[i] == "В наявності") 
                    {
                        status[i] = "Позичено";
                        cout << "Книгу " << books[i] << " Позичено\n";
                    } 
                    else if (choice == 3 && status[i] == "Позичено") 
                    {
                        status[i] = "В наявності";
                        cout << "Книгу " << books[i] << " Повернено\n";
                    } 
                    else 
                    {
                        cout << "Книга вже є позичена або повернута\n";
                    }
                    break;

                }
                else if (i == N - 1) 
                {
                    cout << "Книга не існує\n";
                }
            }
        }

    } while (choice != 4);
    
    cout << "Вихід\n";
    return 0;
}