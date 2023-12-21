#include <iostream>

using namespace std;


string book_names[] = {
    "Книга 1",
    "Книга 2",
    "Книга 3",
    "Книга 4",
    "Книга 5",
    "Книга 6",
    "Книга 7",
    "Книга 8", 
    "Книга 9",
    "Книга 10"
};
int book_amount = 10;
bool book_availabilities[10] = {
    true, true, true, true, true, true, true, true, true, true
};


int main() {
  
  label:
  cout << "1.Перерахувати книги" << endl;
  cout << "2.Взяти книгу" << endl;
  cout << "3.Повернути книгу" << endl;
  cout << "4.Вийти" << endl;

  int choice;
  cout << "Ваш вибір: ";
  cin >> choice;

  switch (choice) {
    case 1:
        for (int i = 0; i < book_amount; i++) {
            if (book_availabilities[i]) {
                cout << "Книга <<" << book_names[i] << ">> доступна" << endl;
            } else {
                cout << "Книга <<" << book_names[i] << ">> недоступна" << endl;
            }
        }
        break;

    case 2:
        for (int i = 0; i < book_amount; i++) {
            if (book_availabilities[i]) {
                cout << i + 1 << ". " << book_names[i] << endl;
            }
        }

        int book_number;
        cin >> book_number;

        if (book_availabilities[book_number - 1]) {
            book_availabilities[book_number - 1] = false;
            cout << "Книга " << book_names[book_number - 1] << " взята" << endl;
        } else {
            cout << "Книга " << book_names[book_number - 1] << " недоступна" << endl;
        }
        break;

    case 3:
        cout << "Взяті книги: " << endl;
        for (int i = 0; i < book_amount; i++) {
            if (!book_availabilities[i]) {
                cout << i + 1 << ". " << book_names[i] << endl;
            }
        }

        int returned_book_number;
        cin >> returned_book_number;

        if (!book_availabilities[returned_book_number - 1]) {
        book_availabilities[returned_book_number - 1] = true;
        cout << "Книга " << book_names[returned_book_number - 1] << " повернена" << endl;
        } else {
        cout << "Книга " << book_names[returned_book_number - 1] << " не була взята" << endl;
        }
        break;

    case 4:
      return 0;

    default:
      cout << "Неправильний вибір. Виберіть опцію з 1 по 4." << endl;
      goto label;

  }

  if (choice != 4) {
    goto label;
  }

  return 0;
}
