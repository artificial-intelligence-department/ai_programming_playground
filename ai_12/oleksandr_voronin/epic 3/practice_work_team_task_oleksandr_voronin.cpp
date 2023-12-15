#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main(){

    vector<string>books ={"Atlant", "1984", "Pepa Pig", "Game of thrones"};
    vector<bool>available ={true, true, true, true};

    int choice;
    string bookName;
    char continueChoice;
    bool exit =false;
    while(!exit){
        menu:
        cout << "__LIBRARY__ \n";
        cout << "1. List all books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";

        cin >> choice;
    
        switch (choice)
        {
        case 1:
            for(int i=0;i<books.size();i++)
            {
                cout << i + 1  << ". " << books[i] << (available[i] ? " (Available)" : " (Borrowed)") << "\n";
            }
            break;
        case 2:
            cout << "Which book you want to take \n";
            cin.ignore();
            getline(cin, bookName);
            for(const auto &book : books)
            {
                if(book==bookName)
                {
                    if(available[&book - &books[0]])
                    {
                        available[&book - &books[0]]= false;
                        cout << "Book is borrowed: " << bookName << endl;
                    }
                    else
                    {
                        cout << "Sorry,this book is already borrowed \n";
                    }
                    break;
                }
            }
            break;
        case 3:
            cout << "Which book you want to return \n";
            cin.ignore();
            getline(cin, bookName);
            for(const auto &book : books)
            {
                if(book==bookName)
                {
                if(!(available[&book - &books[0]]))
                    {
                        available[&book - &books[0]]= true;
                        cout << "Book is returned " << bookName << endl;
                        break;
                    }
                    else
                    {
                        cout << "Book wasn't borrowed.\n";
                        break;
                    }
                }
            }
            break;
        case 4:
            cout << "Bye" <<endl;
            return 0;
            break;
        default:
            cout << "Uncorrect choice" << endl;
            goto menu;
        }
        
        do{
        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> continueChoice;
        }while (continueChoice != 'Y' && continueChoice != 'N' && continueChoice != 'y' && continueChoice != 'n');


    if (continueChoice == 'Y' || continueChoice == 'y') {
        goto menu;
    } else {
        cout << "Goodbye!";
        exit = true;
    }

    }   
    return 0;
}