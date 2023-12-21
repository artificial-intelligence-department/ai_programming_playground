#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main()
{
    int a=0;
    string book;
    char option;
    vector<bool>availabl={true,true,true,true};
    vector<string>books = {"Dorian Gray", "The song of fire and ice", "The Witcher", "The Hobbit"};
    Menu:
    cout<<"1-Available books"<<endl;
    cout<<"2-take book"<<endl;
    cout<<"3-return book"<<endl;
    cout<<"4-quit"<<endl;
    cin>>option;
    switch (option)
    {
        case '1':
            for(int i=0;i<books.size();i++)
                cout<<books[i]<<endl;
            break;

        case '2':
            cin.ignore();
            cout<<"Name book you want to take: "<<endl;
            getline(cin,book);
            for(int i=0;i<books.size();i++){
                if (books[i]==book && availabl[i]==true)
                {
                    cout<<"You took a book:"<<book<<endl;
                    availabl[i]=false;
                    a++;  
                    break;
                }
            }
            if(a==0)
                cout<<"not available or not exist(or already borrowed)"<<endl;
            a=0;
            break;
        case '3':
            cin.ignore();
            cout<<"Name book you want to return: "<<endl;
            getline(cin,book);
            for(int i=0;i<books.size();i++){
                if (books[i]==book && availabl[i]!=true){
                    cout<<"You return a book:"<<book<<endl;
                    availabl[i]=true;
                    a++;
                }
            }
            if(a==0)
                cout<<"not exist(or not borrowed)"<<endl;
            break;
        case '4':
            cout<<"You are always welcome!";
            return 0;
        default:
            cout<<"Try again: ";
            goto Menu;
    }       
    string choise;
    cout<<"Do you want to go to menu again? (Yes/No): ";       
    cin>>choise; 
    if(choise=="Yes")
        goto Menu;      
    return 0;
}