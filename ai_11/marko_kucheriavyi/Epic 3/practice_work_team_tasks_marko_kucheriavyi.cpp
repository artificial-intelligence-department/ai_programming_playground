#include <iostream>
using namespace std;
struct library{
    string name;
    bool availability;
};
void ShowTheLibrary(library* arr, int size){
    for (int i = 0; i < size; i++){
        if (arr[i].availability == true){
            cout << "-------" << arr[i].name << endl;
        }
    }
}
void TakeTheBook(library* book, library* borrowed, int size, string name){
    bool a = false;
    for (int i = 0; i < size; i++){
        if (name == book[i].name && book[i].availability == true){
            book[i].availability = false;
            borrowed[i].availability = true;
            a = true;
            cout << "You have successfully borrowed a book" << endl;
        }
    }
    if (a == false){
        cout << "Book is not available" << endl;
    }
}
void ReturnTheBook(library* book, library* borrowed, int size, string name){
    bool a = false;
    for (int i = 0; i < size; i++){
        if (name == borrowed[i].name && borrowed[i].availability == true){
            book[i].availability = true;
            borrowed[i].availability = false;
            a = true;
            cout << "The return of the book is successful" << endl;
        }
    }
    if (a == false){
        cout << "You didn't borrow this book!" << endl;
    }
}
int main(){
    library book[] = {{"Harry Potter", 1},
                        {"The Hobbit", 1},
                        {"Pride and Prejudice", 1},
                        {"Lord of the rings", 1}};
    int SizeOfLibrary = sizeof(book) / sizeof(book[0]), WhatToDo;
    library borrowed[SizeOfLibrary];
    for (int i = 0; i < SizeOfLibrary; i++){
        borrowed[i].name = book[i].name; 
        borrowed[i].availability = false;
    } 
    string DesiredBook;
    cout << "Welcome to the library!" << endl << "Here is some tips for you:" << endl;
    cout << "1. List a books" << endl << "2. Take a book" << endl ;
    cout << "3. Return a book" << endl << "4. Exit" << endl;
    do{
        cout << "Enter the number: ";
        if (!(cin >> WhatToDo)){
            cin.clear();
            cin.ignore();
        }
        switch (WhatToDo){
        case 1:
            cout << endl << "Available books:" << endl;
            ShowTheLibrary(book, SizeOfLibrary);
            break;
        case 2:
            cout << endl << "Available books:" << endl;
            ShowTheLibrary(book, SizeOfLibrary);
            cout << "What book would you like to borrow?: ";
            cin.ignore();
            getline(cin, DesiredBook);
            TakeTheBook(book, borrowed, SizeOfLibrary, DesiredBook);
            break;
        case 3:
            cout << endl << "Borrowed books:" << endl;
            ShowTheLibrary(borrowed, SizeOfLibrary);
            cout << "What book would you like to return?: ";
            cin.ignore();
            getline(cin, DesiredBook);
            ReturnTheBook(book, borrowed, SizeOfLibrary, DesiredBook);
            break;
        case 4:
            cout << "Thank you for using my library!";
            break;
        default:
            cout << "Enter the right number!";
            break;
        }
        cout << endl;
    }while (WhatToDo != 4);
    return 0;
}