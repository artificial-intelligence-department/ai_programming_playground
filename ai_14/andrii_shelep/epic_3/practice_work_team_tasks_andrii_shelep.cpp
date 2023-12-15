#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string borrowBook, giveBook;
    vector<string> borrowed = {"-", "-", "-", "-"};
    vector<string> availability = {"(Доступна)", "(Доступна)", "(Доступна)", "(Доступна)"};
    vector<string> books = {"Harry Potter", "The Hobbit", "Pride and Prejudice", "1984"};
    int choice;
    bool cond = true;
    bool working = true;
    while (working == true){
    Menu:
        cout << "0 - Вийти \n1 - Позичити книгу \n2 - Повернути книгу \n3 - Перерахувати книги\n";
        cin >> choice;

        if (choice!= 0 && choice != 1 && choice != 2 && choice != 3){
            cout << "виберіть ще раз" << endl;
            goto Menu;
        } else {
            if (choice==3){
                for (int i = 0; i < books.size(); i++){
                    cout << "\n" << i+1 << " " << "\"" << books[i] << "\"" << " " << availability[i] << " " <<"\n";
                }
            } else if (choice == 1){
                cout << "Виберіть книгу, яку хочете позичити: ";
                for (int i = 0; i < books.size(); i++){
                    cout << "\n" << i+1 << " " << "\"" << books[i] << "\"" << " " << availability[i] << " " <<"\n";
                }
                cin.ignore();
                getline(cin, borrowBook);

                for(const auto &book : books){
                    if (book == borrowBook){
                        int i = &book - &books[0];
                        if(availability[i]=="(Доступна)"){
                            cout << "ви взяли книгу " << "\"" << books[i] << "\"" << endl;
                            availability[i] = "(Недоступна)";
                            borrowed[i] = {books[i]};
                        } else{
                            cout << "Ця книга недоступна" << endl;
                        }
                        cond = false;
                        break;
                    } else{
                        cond = true;
                    }
                }
                if(cond == true){
                    cout << "Помилка" << endl;
                }
            } else if (choice == 2){
                cout << "Яку книгу ви хочете повернути?";
                for (int i = 0; i < 4; i++){
                    cout << "\n" << i+1 << " " << "\"" << borrowed[i] << "\"" << " " << " " <<"\n";
                }
                cin.ignore();
                getline(cin, giveBook);
                for(int i = 0; i < borrowed.size(); i++){
                    if (giveBook == borrowed[i] && availability[i]!="(Доступна)"){
                        cout << "ви повернули книгу " << "\"" << giveBook << "\"" << endl;
                        availability[i] = "(Доступна)";
                        borrowed[i] = "-";
                        cond = false;
                        break;
                    } else if(giveBook == borrowed[i] && availability[i]=="(Доступна)") {
                        cout << "Щось пішло не так" << endl;
                        cond = false;
                        break;
                    }
                }
                if (cond == true){
                    cout << "Помилка! Схоже ви ввели щось неправильно(" << endl;
                    goto Menu;
                }
            } else if (choice == 0){
                cout << "bye";
                break;
            }

            do{
                cout << "Чи бажаєте ви виконати іншу операцію?\n1 - так\n2 - ні\n";
                int k;
                cin >> k;
                if (k == 1){
                    goto Menu;
                } else if (k == 2){
                    cout << "bye";
                    working = false;
                    break;
                } else {
                    cout << "Спробуйте ще раз" << endl;
                }
            } while (true);  
        }
    }
    return 0;
}