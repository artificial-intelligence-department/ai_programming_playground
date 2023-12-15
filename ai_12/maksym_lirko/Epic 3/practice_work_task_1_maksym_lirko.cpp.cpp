#include<iostream>
#include<string>
using namespace std;

 int main(){

    string books[3]={"Harry_Poter", "Hobbit", "1984"};
    const int BOOKSIZE=sizeof(books)/sizeof(books[0]);
    char choice2;
    bool a;

    bool available[BOOKSIZE] = {true, true, true};
    
    int action;
    string bookname;

    choice:
    cout<<"Enter an action"<<endl;
    cout<<"1.List of books"<<endl;
    cout<<"2.Take a book"<<endl;
    cout<<"3.Return a book"<<endl;
    cout<<"4.Exit from menu"<<endl<<endl;
    cout<<"Enter an action:"<<endl;
    cin>>action;

    switch (action)
    {
    case 1:
        for (int i = 0; i < BOOKSIZE; i++)
        {   
            cout<<"||"<<books[i]<<endl;
        }
        break;
    case 2:
        cout<<"Enter the title of book to take: "<<endl;
        cin>>bookname;
        for (int i2 = 0; i2 < BOOKSIZE; i2++)
        {
            if (books[i2]==bookname)
            {
                    if (available[i2])
                {
                    cout<<"You have successfully taken the book"<<endl;
                    available[i2]=false;
                    break;
                }
                else
                {
                    cout<<"This book has already taken!"<<endl;
                    break;
                }
                
            }  
        }
        break;
    case 3:
        for (int i = 0; i < BOOKSIZE; i++)
        {
            cout<<books[i]<<endl;
        }
        cout<<"Enter a book which you want to return: "<<endl;
        cin>>bookname;
        for (int i3 = 0; i3 < BOOKSIZE; i3++)
        {
            if(books[i3]==bookname)
            {
                if(!available[i3])
                {
                    cout<<"Your book successfully returned!"<<endl;
                    available[i3]=true;
                    break;
                }
                else
                {
                    cout<<"You dont took this book!"<<endl;
                    break;
                }
            }
        }
        
        break;
    case 4:
        cout<<"Bye!"<<endl;
        return 0;
    
    default:
        cout<<"Wrong input!!"<<endl;
        cout<<"Try again!"<<endl<<endl;
        return 0;
    }

    do
    {
        cout<<"Do you want to continue?(Y/N): "<<endl;
        cin>>choice2;
        if(choice2=='Y')
        {
            a = true;
            goto choice;
        }
        else if (choice2 == 'N')
        {
            a = true;
            cout<<"Bye!"<<endl;
        }
    } while(a != true);

    return 0;
}

 
 