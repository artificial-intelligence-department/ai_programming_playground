#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;


int main()
{
    int choice;
    int t = 0;
    bool check = false;
    bool check2 = false;
    string choice1 , choice2 , search , borrow, returnb;

    vector<string> books = {"Harry Potter", "The Hobbit" , "Pride and Prejudice", "1984"};
    vector<string> existing = books;
    vector<string> bookbackup = books;
    start:
        cout << "--------------------"<< endl;
        cout <<"What u wanna do?" << endl;
        cout <<"1.See the book list" << endl;
        cout <<"2.Find a book in the book list" << endl;
        cout <<"3.U wanna borrow a book?" << endl;
        cout <<"4.U wanna return a book?" << endl;
        cout <<"5.Exit" << endl;
        cout << "--------------------"<< endl;
        cout <<"enter the appropriate number: ";
        cin >> choice;
        if (choice == 1)
        {  
            while(true)
            {
                cout << "Book list: " << endl;
                for (int i = 0; i < books.size(); i++)
                {
                    cout << books[i] << endl;
                }
            cout <<"\nDo u wanna continue(Yes/No): "<< endl;
                getline(cin , choice1);
                for (char &c1 : choice1)
                {
                    c1 = tolower(c1);
                }

                if (choice1 == "yes")
                {
                    goto start;
                }

                else if(choice1 == "no")
                    exit(0);
            }
        }
        if (choice == 2)
        {
            do
            {
                cout << "Enter the book u are looking for: ";
                cin.ignore();
                getline(cin , search);
                if (find(books.begin(), books.end() , search) != books.end())
                    cout << search << " is available in the list" << endl;
                else
                    cout << search << " is not available in the list or it has not in out list" << endl;
                
                cout <<"Do u wanna continue(Yes/No or u wanna exit?): ";
                getline(cin , choice2);
                for (char &c2 : choice2)
                {
                    c2 = tolower(c2);
                }
                if (choice2 == "yes"){
                    continue;
                }
                
                
                if (choice2 == "no")
                {
                    goto start;
                }
            }   
            
            while(choice2 != "exit");
        }
        if (choice == 3)
            {
                cout << "Enter a book u wanna borrow: ";
                cin.ignore();
                getline(cin , borrow);
                for(int i = 0; i < books.size();i++)
                {
                    if (borrow == existing[i])
                    {
                        books[i] = "Is Borrowed: " + borrow;
                        existing[i] = "";
                        check = true;
                    }
                }
                if(check)
                    {
                        cout << "book was borrow successfully" << endl;
                        Sleep(3000);    
                        goto start;
                    }
                if (!check){
                        cout << "The book is already borrowerd or it hasnt in our list";
                        Sleep(3000);
                        goto start;
                    }
                }
        if (choice == 4)
        {
            cout << "Enter a book u wanna return: ";
            cin.ignore();
            getline(cin, returnb);
            for(int i = 0; i < books.size();i++)
            {
                if(returnb == bookbackup[i] && existing[i] == "")
                {
                    existing[i] = returnb;
                    books[i] = returnb;
                    check2 = true;
                }
            }
                if (check2){
                        cout << "The book was returned successfully" <<endl;
                        Sleep(3000);
                        goto start;
                    }
                if (!check2){
                    cout << "The book is available or it has not in our list";
                    Sleep(3000);
                    goto start;
                }
        }
    return 0;


}