#include<iostream>
#include<vector>
#include<string>
using namespace std;
void listavailibleBooks(vector<string>books, vector<bool>availible){
    int i=0;
    cout<<"This is list of availible books:\n";
    for (auto &&book : books)
    {
     cout<<i+1<<") "<<book<<(availible[i]?" -availible" : " -is not availible")<<"\n";
         i=i+1;
    }
} 
int mainmenu(int sizeoflibrary){
    int action;
    
    cout<<"What do you want to do?\n";
    cout<<"1. List all availible books\n";
    cout<<"2. Take book\n";
    cout<<"3. Return book\n";
    cout<<"4. Exit\n";
    cin>>action;

    return action;
}
vector<bool> takebook(vector<bool>availible){
    int bookindex;
    cout<<"What book do you want to take?:\n";
    cin>>bookindex;
    if(bookindex!=1 && bookindex!=2 && bookindex!=3 && bookindex!=4){
        cout<<"Invalid choice\n";
        return availible;
        }else if(availible[bookindex-1]==0){
        cout<<"We dont have that book!\n";
        return availible;
    } 
    cout<<"You borrowed a book\n";
    availible[bookindex-1]=0;

    return availible;
}
vector<bool> returnbook(vector<bool>availible){
    int bookindex;
    cout<<"What book do you want to return?:\n";
    cin>>bookindex;
    if(bookindex!=1 && bookindex!=2 && bookindex!=3 && bookindex!=4){
        cout<<"Invalid choice\n";
        return availible;
        }else if(availible[bookindex-1]==1){
        cout<<"We already have that book!\n";
        
        return availible;
    }
    cout<<"You returned a book to the library\n";
    availible[bookindex-1]=1;
    return availible;
}
int main(){
    vector<string>books={"1984","Lord of the flies","The end of eternity","Scott Pilgrim and his precious little life"};
    int sizeoflibrary = size(books);
    vector<bool>availible(sizeoflibrary,1);
    char choice;
    
menu:
    switch (mainmenu(sizeoflibrary))
    {
    case 1 :
        listavailibleBooks(books,availible);
        goto menu;
        break;
    case 2 :
       availible = takebook(availible);
       break;
    case 3 :
       availible = returnbook(availible);
       break;
    case 4 :
       cout<<"Goodbye<3";
       return 0;
    default:
       cout<<"Invalid action\n";
       goto menu;
       break;
    }

    do {
        cout << "Do you want to perform another operation? y/n\n ";
        cin >> choice;
    } while (choice != 'y' && choice != 'n');

    if ( choice == 'y') {
       goto menu;
    } else if(choice == 'n') {
        cout << "Goodbye<3";
        return 0;
    }
}
