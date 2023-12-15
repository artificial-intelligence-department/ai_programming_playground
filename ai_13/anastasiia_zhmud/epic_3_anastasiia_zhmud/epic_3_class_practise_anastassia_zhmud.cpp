#include<iostream>
#include<string>
using namespace std;
int main(){
    string books[4]= {"Kobzar", "Aeneid", "City", "Moment"};
    bool availability[4]={true, true, true, true};
    int key=0;
    string contin;
    
    do{
    menu:
    key=0;
    int action;
    cout<<"Libruary management\n";
    cout<<"1. List of books\n";
    cout<<"2. Take a book\n";
    cout<<"3. Return book\n";
    cout<<"4. Finish\n\n";
    cout<<"Enter a number: ";
    cin>>action;

    switch (action){
    case 1:{
        for (int i=0; i<4; i++){
            cout<<books[i]<<"   ";
        }
        cout<<"\nDo you want to do something else? (Y/N):  ";
        cin>>contin;
        break;
    }
    case 2:{
        string bookname;
        cout << "\nEnter book name to borrow: ";
        cin>>bookname;
        for(int i=0; i<4; i++){
            if(bookname == books[i]){
                if(availability[i]==true){
                availability[i]=false;
                cout<<"You have successfully taken the book!";
                key = 1;
                }
                else cout<<"Book is already borrowed";
                key = 1;
            }
        }
    }
        if(key==0){
            cout<<"Your input is wrong. Please, try again.\n";
            goto menu;
        }
        cout<<"\nDo you want to do something else? (Y/N):  ";
        cin>>contin;
        break;
        
    case 3:{
        string bookname;
        cout << "\nEnter book name to return: ";
        cin>>bookname;
        for(int i=0; i<4; i++){
            if(bookname == books[i]){
                if(availability[i]==false){
                availability[i]=true;
                cout<<"You have successfully return the book!";
                key = 1;
                }
                else cout<<"Book is already returned";
                key = 1;
            }
        }
        if(key==0){
            cout<<"Your input is wrong. Please, try again.\n";
            goto menu;
        }
        cout<<"\nDo you want to do something else? (Y/N):  ";
        cin>>contin;
        break;
    }
    case 4:{
        cout<<"Goodbye!";
        contin="N";
        break;
    }
    default:{
        cout<<"Your input is wrong. Please, try again.\n";
        goto menu;
    }
    }
    }
    while(contin=="Y");
}