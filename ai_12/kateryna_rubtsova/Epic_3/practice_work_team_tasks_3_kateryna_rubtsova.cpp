#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string book1, book2, book3;
    int bookret;
    
    vector<string> books ={"Book1", "Book2", "Book3"};
    vector<bool> avi ={true, true, true};
    
    menu:
    cout<<"1.Перерахувати наявні книги.\n";
    cout<<"2.Взяти книгу.\n";
    cout<<"3.Повернути книгу.\n";
    cout<<"4.Вийти з книгарні.\n";
        
    int choise;
    cin>>choise;
    switch(choise){
        case 1:
            if(avi[0] == true){
                book1 = books[0];
                cout<<book1<<"\n";
            }
            if(avi[1] == true){
                book2 = books[1];
                cout<<book2<<"\n";
            }
            if(avi[2] == true){
                book3 = books[2];
                cout<<book3<<"\n";
            }
            goto menu; 
                     
        case 2:
            cout<<"Яку книгу хочете взяти?\n";
            int bookchoise;
            cin>>bookchoise;
            if(bookchoise == 1){
                if(avi[0] == true){
                    cout<<"Ви взяли першу книгу.\n";
                    avi[0] = false;
                }else{
                    cout<<"Ви вже взяли цю книгу.\n";
                }
            }else if(bookchoise == 2){
                if(avi[1] == true){
                    cout<<"Ви взяли другу книгу.\n";
                    avi[1] = false;
                }else{
                    cout<<"Ви вже взяли цю книгу.\n";
                }
            }else if (bookchoise == 3){
                if(avi[2] == true){
                    cout<<"Ви взяли третю книгу.\n";
                    avi[2] = false;
                }else{
                    cout<<"Ви вже взяли цю книгу.\n";
                }
            }else{
                cout<<"Цієї книги не існує.\n";
            }
            goto menu;
        case 3:
            cout<<"Яку книгу хочете повернути?\n";
            cin>>bookret;
            if(bookret == 1){
                if(avi[0] == false){
                    avi[0] = true;
                    cout<<"Ви повернули першу книгу.\n";
                }else{
                    cout<<"Ви не брали цієї книги.\n";
                }
            }
            if(bookret == 2){
                if(avi[1] == false){
                    avi[1] = true;
                    cout<<"Ви повернули другу книгу.\n";1
                    
                }else{
                    cout<<"Ви не брали цієї книги.\n";
                }
            }
            if(bookret == 3){
                if(avi[2] == false){
                    avi[2] = true;
                    cout<<"Ви повернули третю книгу.\n";
                }else{
                    cout<<"Ви не брали цієї книги.\n";
                }
            }
            goto menu;
        case 4:
            cout<<"Бувайте!";
            break;
        default:
            cout<<"error";
            break;
    }
        
    return 0;
}
