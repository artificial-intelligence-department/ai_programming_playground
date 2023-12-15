#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){
    vector<string> books = {"Harry potter", "Animal Farm", "Fahrenheit 451", "Alchemist", "Lord of the rings"};
    vector<bool> available(5,true);
    int choice, dcsn, num;
    string y_n;
    bool ctn = true;
    Initial_menu:
    while(ctn){
    cout<<"Hello! How can i help you? (Choose from the list)"<<endl;
    cout<<"1. List all available books."<<endl;
    cout<<"2. Leave"<<endl;
    cin>>dcsn;
        switch (dcsn){ 
            case 1:
            cout<<"List of all books:"<<endl;
            for (int i=0; i <5; i++) {
                cout<<i+1<<". "<<books[i]<<" ("<< (available[i] ? "Available":"Borroved")<<")"<<endl; 
            }
            cout<<"What do you want?"<<endl;
            cout<<"1. Borrow a book"<<endl;
            cout<<"2. Return a book"<<endl;
            cout<<"3. Return back"<<endl;
            cin>>choice;
            if (choice == 1){
            cout<<"What book do you want to borrow(number of a book)?"<<endl;
            cin>>num;
                if (num>=1 && num<=5){
                    if (available [num - 1]){
                        available [num - 1] = false;
                        cout<<"You've borrowed: "<<books [num - 1]<<""<<endl;
                    
                }else
                    cout<<"This book is already borrowed"<<endl;
        }else
                cout<<"Please enter correct number of a book"<<endl;
                goto Initial_menu; }

            else if(choice == 2){
                cout<<"What book do you want to return(number of a book)?"<<endl;
            cin>>num;
                if (num>=1 && num<=5){
                    if (!available [num - 1]){
                        available [num -1] = true;
                        cout<<"You've returned: "<<books [num - 1]<<""<<endl;
                    
                }else
                    cout<<"This book is already available"<<endl;
        }else{
                cout<<"Please enter correct number of a book"<<endl;
                goto Initial_menu;} 
                }
            else if(choice ==3){
                goto Initial_menu;
            }
            else
            cout<<"Error"<<endl;
               

            
            break;
            case 2:
            cout<<"Are you sure? "<<endl;
            cin>>y_n;
            if(y_n == "Yes"|| y_n == "YES"|| y_n == "yes"){
                ctn = false;
                }
            else
            goto Initial_menu;
            break;
        }
    }
    return 0;
}