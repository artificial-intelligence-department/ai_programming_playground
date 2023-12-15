#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main(){
    vector<string> books = {"HarryPotter", "The Hobbit", "The Fight Club", "1984"};
    vector<bool> condition = {true, true, true, true};

    int choise;
    string name;

    while (true)
    {
        menu:
            cout << "\tMenu" << endl;
            cout << "1. List all books" << endl;
            cout << "2. Borrow a book" << endl;
            cout << "3. Return a book" << endl;
            cout << "4. Exit" << endl;

            cout << "Enter your choise" << endl;
            cin >> choise;

            switch (choise)
            {
            case 1:
                for(int count = 0;count < books.size();count++){
                    cout << count+1 << '.' << books[count] << (condition[count]? "available":" not available");
                    goto menu;
                }
            
            case 2:
                cout << "Enter name of your book" << endl;
                cin >> name;
                
                bool BookWasntFound = false;
                for(int i = 0;i < books.size();i++)
                    if(name == books[i]){
                        if(condition[i]){
                            cout << "You borrowed the book successfully" << endl;
                            condition[i] = false;
                            BookWasntFound = true;
                        }
                        else
                            cout << "Unfortunately your book isnt available" << endl;
                    }

                if(BookWasntFound){
                    cout << "You entered wrong name" << endl;
                    goto menu;
                }

            case 3:
                cout << "Enter name of your book" << endl;
                cin >> name;
                
                bool BookWasntFound = false;
                for(int i = 0;i < books.size();i++)
                    if(name == books[i]){
                        if(!condition[i]){
                            cout << "You returned the book successfully" << endl;
                            condition[i] = true;
                            BookWasntFound = true;
                        }
                        else
                            cout << "Unfortunately your book isnt taken" << endl;
                    }

                if(BookWasntFound){
                    cout << "You entered wrong book name" << endl;
                    goto menu;
                }
            case 4:
                cout << "Bye-bye" << endl;
            
            }
    }
    return 1;
}