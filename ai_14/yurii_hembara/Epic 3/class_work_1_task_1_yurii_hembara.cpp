#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> books = {"Book1", "Book2", "Book3", "Book4"};
    vector<bool> availability = {true, true, true, true};
    int choice;

    main_menu:

    cout << "Choose one option:\n";
    cout << "1. List all books\n";
    cout << "2. Borrow a book\n";
    cout << "3. Return a book\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: // Список усіх книг
            cout << "List of all books:\n";
            for (const auto &book : books) {
                cout << book << endl;
            }
            break;

        case 2: // Позичити книгу
            cout << "Enter name of the book you want to borrow: ";
            {
                string bookToBorrow;
                cin >> bookToBorrow;

                int index = -1;
                for (int i = 0; i < books.size(); ++i) {
                    if (books[i] == bookToBorrow && availability[i]) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    cout << "You borrowed: " << bookToBorrow << endl;
                    availability[index] = false;
                } else {
                    cout << "Book not available or does not exist. Please enter corrext book name.\n";
                }
            }
            break;

        case 3: // Віддати книгу
            cout << "Enter the book you want to return: ";
            {
                string bookToReturn;
                cin >> bookToReturn;

                int index = -1;
                for (int i = 0; i < books.size(); ++i) {
                    if (books[i] == bookToReturn && !availability[i]) {
                        index = i;
                        break;
                    }
                }

                if (index != -1) {
                    cout << "You returned: " << bookToReturn << endl;
                    availability[index] = true;
                } else {
                    cout << "Book not borrowed or does not exist. Please enter corrext book name.\n";
                }
            }
            break;

        case 4: // Вихід
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
            goto main_menu;
    }

    // Запит користувача про виконання іншої операції
    int continueChoice;
    cout << "Do you want to perform another operation? (1 for Yes, 0 for No): ";
    cin >> continueChoice;

    if (continueChoice) {
        goto main_menu;
    } else {
        cout << "\n";
        return 0;
    }
}
