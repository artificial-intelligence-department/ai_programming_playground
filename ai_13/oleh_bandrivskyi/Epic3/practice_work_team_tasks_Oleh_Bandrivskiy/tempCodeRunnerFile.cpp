#include <iostream>
#include <string>

using namespace std;

int main(){


    const int MaxBooks = 3;

    string books[MaxBooks] = {"You", "1984", "Hobit"};
    bool available[MaxBooks] = {true, true, true};
    char action;
    string bookName;
    int BookNumber;

    menu:
    cout << "Library Menu:" << endl;
    cout << "1. List of books" << endl;
    cout << "2. Borrow a book" << endl;
    cout << "3. Return a book" << endl;
    cout << "4. Exit" << endl;
    cin >> action;

    switch (action)
    {
    case '1':
        for(int i = -1; i < MaxBooks; i++){
            cout << i + 1 << "." << books[i] << ":" << (available[i] ? "available" : "borrowed") <<endl;
        }
        break;
    case '2':

        cout << "Enter your book name:";
        cin >> bookName;

        for(const auto&book:books){
            if(book == bookName){
                int index = &book - &books[0];
                if(available[index]){
                    available[index] = false;
                    cout << "You successfully borrow your book" << endl;
                    break;
                }else{
                    cout << "Your book is borrowed" << endl;
                }
                break;
            }
        }
        break;
    case '3':
        cout << "Enter your book name:";
        cin >> bookName;

        for(const auto&book:books){
            if(book == bookName){
                int index = &book - &books[0];
                if(!available[index]){
                    available[index] = true;
                    cout << "You successfully return your book" << endl;
                    break;
                }else{
                    cout << "Your book no borrowed" << endl;
                }
                break;
            }
        }
        break;
    case '4':
        cout << "Goodbey";
        return 0;
        break;
    default:
        cout << "Envalid case" << endl;
        goto menu;
        break;
    }
    return 0;
}