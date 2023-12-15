#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void displayBooks(const vector<string> &titles, const vector<bool> &availability) {
    printf("--------------------------------------------\n");
    printf("%-20s\t%-15s\n", "Назва книги", "Доступність");
    printf("--------------------------------------------\n");

    for (int i = 0; i < titles.size(); ++i) {
        printf("%-20s%-15s\n", titles[i].c_str(), (availability[i] ? "Доступна" : "Взята"));
    }

    printf("--------------------------------------------\n");
}

int main() {
    vector<string> bookTitles = {"Parfume", "Ivanhoe", "Faust"};
    vector<bool> availability = {true, true, true};
    int choice = 0;

    while (choice != 4) {
        
        menu:
        printf("1. Перерахувати всі книги\n");
        printf("2. Взяти книгу\n");
        printf("3. Повернути книгу\n");
        printf("4. Вийти\n");
        printf("Оберіть опцію: ");
        cin >> choice;

        if (choice == 1) {
            displayBooks(bookTitles, availability);
        } else if (choice == 2) {
            printf("Оберіть книгу для позичання:\n");
            displayBooks(bookTitles, availability);

            string borrowTitle;
            bool bookFound = false;

            do {
                printf("Введіть назву книги (або '0' для повернення до головного меню): ");
                cin >> borrowTitle;

                if (borrowTitle == "0") {
                    goto menu;
                }

                for (const auto &title : bookTitles) {
                    if (title == borrowTitle) {
                        int index = &title - &bookTitles[0];
                        if (availability[index]) {
                            availability[index] = false;
                            printf("Ви взяли книгу '%s'.\n", title.c_str());
                            bookFound = true;
                            break;
                        } else {
                            printf("Ця книга вже взята. Спробуйте знову або введіть '0' для повернення до головного меню.\n");
                        }
                    }
                }

                if (!bookFound) {
                    printf("Неправильна назва. Спробуйте знову або введіть '0' для повернення до головного меню.\n");
                }
            } while (!bookFound);
        } else if (choice == 3) {
            printf("Введіть назву книги для повернення:\n");
            displayBooks(bookTitles, availability);

            string returnTitle;
            bool returnFound = false;

            do {
                printf("Введіть назву книги (або '0' для повернення до головного меню): ");
                cin >> returnTitle;

                if (returnTitle == "0") {
                    goto menu;
                }

                for (const auto &title : bookTitles) {
                    if (title == returnTitle) {
                        int index = &title - &bookTitles[0];
                        if (!availability[index]) {
                            availability[index] = true;
                            printf("Ви повернули книгу '%s'.\n", title.c_str());
                            returnFound = true;
                            break;
                        } else {
                            printf("Ця книга вже доступна. Спробуйте знову або введіть '0' для повернення до головного меню.\n");
                        }
                    }
                }

                if (!returnFound) {
                    printf("Неправильна назва. Спробуйте знову або введіть '0' для повернення до головного меню.\n");
                }
            } while (!returnFound);
            
        } else if (choice == 4) {
            printf("Заходіть ще!\n");
        } else {
            printf("Неправильний вибір. Спробуйте знову.\n");
            goto menu;
        }

        if (choice != 4) {
            char continueChoice;
            printf("Бажаєте виконати іншу операцію? (y/n): ");
            cin >> continueChoice;

            if (continueChoice != 'y' && continueChoice != 'Y') {
                printf("Заходіть ще!\n");
                break;
            }
        }
    }

    return 0;
}
