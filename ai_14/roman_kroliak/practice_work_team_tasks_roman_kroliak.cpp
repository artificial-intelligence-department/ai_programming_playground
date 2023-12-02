#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    bool cont = true;
    bool other_op;
    vector<string> book_names = {"Harry Potter", "Kobzar", "The Churchill Factor", "Shadows of Forgotten Ancestors", "1984", "Treasure Island", "Miss Peregrine's Home for Peculiar Children"};
    bool book_availability[book_names.size()];
    for (bool &avaib : book_availability) avaib = true;
    while(cont){
        do
        {
            int choice;
            cout << "What do you want to do? \n1. Print names of books \n2. Take book \n3. Return book\n";
            choose_op:
            cout << "Your choice:";
            cin >> choice;
            switch (choice)
            {
            case 1:
            {
                for (int i = 0; i < book_names.size(); i++)
                    cout << i+1 << ". " << book_names[i] << endl;
                break;
            }
            case 2:
            {
                vector<int> available_i;
                cout << "Available books:\n";
                int i = 0;
                int j = 0;
                for (bool avaib : book_availability){
                    if (avaib) {
                        cout << j+1 << ". " << book_names[i] << endl;
                        available_i.push_back(i);
                        j++;
                    }
                    i++;
                }
                int book_choice_take;
                cout << "What book do you want to take?\n";
                choose_take:
                cout << "Your choice:";
                cin >> book_choice_take;
                if (book_choice_take <= 0 || book_choice_take > j+1)
                {
                    cout << "Invalid choice. Choose 1-" << j+1;
                    goto choose_take;
                }
                book_availability[available_i[book_choice_take-1]] = false;
                break;
            }
            case 3:
            {
                vector<int> taken_i;
                cout << "Taken books:\n";
                int i = 0;
                int j = 0;
                for (bool avaib : book_availability){
                    if (!avaib) {
                        cout << j+1 << ". " << book_names[i] << endl;
                        taken_i.push_back(i);
                        j++;
                    }
                    i++;
                }
                int book_choice_return;
                cout << "What book do you want to return?\n";
                choose_return:
                cout << "Your choice:";
                cin >> book_choice_return;
                if (book_choice_return <= 0 || book_choice_return > j+1)
                {
                    cout << "Invalid choice. Choose 1-" << j+1;
                    goto choose_return;
                }
                book_availability[taken_i[book_choice_return-1]] = true;
                break;
            }
            default:
            {
                cout << "Invalid operation. Choose 1-3";
                goto choose_op;
            }
            }
            char an_op;
            cout << "Do another operation? (y/n):";
            choose_an_op:
            cin >> an_op;
            switch (an_op)
            {
            case 'y':
                other_op = true;
                break;
            case 'n':
                other_op = false;
                break;
            default:
                cout << "Invalid input. Choose y or n";
                goto choose_an_op;
            }
        } while (other_op);
        char quit;
        cout << "Quit program? (y/n):";
        choose_quit:
        cin >> quit;
        switch (quit)
        {
        case 'y':
            cont = false;
            break;
        case 'n':
            cont = true;
            break;
        default:
            cout << "Invalid input. Choose y or n";
            goto choose_quit;
        }
    }
    return 0;
}