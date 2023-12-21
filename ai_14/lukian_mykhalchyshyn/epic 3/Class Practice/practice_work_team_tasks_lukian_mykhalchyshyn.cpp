#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, action;
    cout << "Вкажіть кількість книг: ";
    cin >> N;

    while (N < 1) {
        cout << "Кількість книг повинна бути хотяб 1: ";
        cin >> N;
    }

    vector<string> books(N);
    vector<string> statuses(N, "Доступно");

    for (int i = 0; i < N; i++) {
        cout << "Вкажіть назву " << i + 1 << " книги: ";
        cin >> books[i];
    }

    do {
        cout << "\n1) Список книг\n";
        cout << "2) Позичити книгу\n";
        cout << "3) Повернути книгу\n";
        cout << "4) Вийти\n\n";
        cout << "Вкажіть дію: ";
        cin >> action;

        while (action < 1 || action > 4) {
            cout << "Дія повинна бути від 1 до 4: ";
            cin >> action;
        }

        if (action == 1) {
            for (int i = 0; i < N; i++) {
                cout << books[i] << " -- " << statuses[i] << "\n";
            }
        } else if (action == 2 || action == 3) {
            cout << "Введіть назву книгу: ";
            string EnteredBook;
            cin >> EnteredBook;

            for (int i = 0; i < N; i++) {
                if (books[i] == EnteredBook) {
                    if (action == 2 && statuses[i] == "Доступно") {
                        statuses[i] = "Позичено";
                        cout << "Книгу " << books[i] << " Позичено\n";
                    } else if (action == 3 && statuses[i] == "Позичено") {
                        statuses[i] = "Доступно";
                        cout << "Книгу " << books[i] << " Повернено\n";
                    } else {
                        cout << "Книгу вже позичено або повернуто\n";
                    }
                    break;
                } else if (i == N - 1) {
                    cout << "Книгу не знайдено\n";
                }
            }
        }

    } while (action != 4);
    
    cout << "Вихід\n";
    return 0;
}