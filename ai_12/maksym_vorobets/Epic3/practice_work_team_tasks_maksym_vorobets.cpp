#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string books[]={"Harry_Potter", "Aftershocks", "Misery", "Icebreaker", "The_Committed"};
    bool available[] = {true , true,true, true, true};
    string operation, availability, bookName, rewiew, exit;
    Menu:
        do{
        cout << "Введіть операцію:" << endl;
        cout << "1. Огляд книг" << endl;
        cout << "2. Вибрати книгу" << endl;
        cout << "3. Вернути книгу"<< endl;
        cout << "4. Вийти" << endl;
        cin >> operation;
     
    if(operation=="1")
    {
        for(int i=0; i<5; i++)
            cout << books[i] << " "<<endl;
          }
          else if(operation=="2")
        {
             cout << "Виберіть:" <<endl;
             cin >> bookName;
           for (int i = 0; i < 5; i++)
              {
            if(bookName==books[i])
            {    
                if(available[i])
                {
                    cout << "Вибрано " << endl;
                    available[i]=false;
               }
                else{
                cout <<"Немає в наявності"<< endl;
              break;   
                }
            }
              }
        }
             else if(operation=="3")
             {
                cout<<"Яку Ви хочете повернути книгу"<<endl;
                cin>>bookName;
            for (int i = 0; i < 5; i++)
           if(bookName==books[i])
        {
                available[i]=true;
            break;
        }  
             }
             else if (operation=="4")
             {
            cout<<"Ви точно хочете вийти?"<<endl;
            cin>>exit;
            if(exit=="No"){
                goto Menu;
            }else;
             }
           }
        while (exit!="Yes");
            
    return 0;
}