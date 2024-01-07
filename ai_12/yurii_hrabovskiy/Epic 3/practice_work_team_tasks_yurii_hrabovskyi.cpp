#include<iostream>
using namespace std;
int main()
{
    string book [] = {"HISTORY", "ENGLISH", "CHEMISTRY", "GEOGRAPHY", "BIOLOGY", "SPANISH"};
    string status [] = {"AVAILABLE", "AVAILABLE", "AVAILABLE", "AVAILABLE", "AVAILABLE", "AVAILABLE"};

    cout<<endl<<"Вітаємо у бібліотеці!"<<endl<<endl;

    while (true)
    {   
        main_menu:
        cout<<endl<<"МЕНЕДЖМЕНТ БІБЛІОТЕКИ"<<endl<<"ВИБЕРІТЬ ДІЮ:"<<endl;
        cout<<endl<< "1. ПЕРЕЛІЧИТИ КНИГИ"<<endl;
        cout<< "2. ПОЗИЧИТИ КНИГУ"<<endl;
        cout<< "3. ПОВЕРНУТИ КНИГУ"<<endl;
        cout<< "4. ПОКИНУТИ ПРОГРАМУ"<<endl<<endl;

        int action;
        cin>>action;
        cout<<endl;

        if (action == 1)
        {
            for(int i=0; i<6; i++)
            {
                cout<<"№"<<i+1<<" "<<book[i]<<" - "<<status[i]<<endl;
            }
            cout<<endl;
        }

        else if (action == 2)
        {
            cout<<"Введіть номер книжки, яку ви б хотіли отримати."<<endl;
            cout<<endl;
            int number;
            cin>>number;
            cout<<endl;
            
                if (status[number-1] == "AVAILABLE")
                {
                    cout<<"Тримайте книгу"<<endl;
                    status[number-1]="NOT AVAILABLE";
                }

                else
                {
                    cout<<"Цієї книги зараз немає."<<endl;
                }
                cout<<endl;
            }

        else if (action == 3)
        {
            cout<<"Введіть номер книжки, яку ви б хотіли повернути."<<endl;
            cout<<endl;
            int number;
            cin>>number;
            if (status[number-1] == "AVAILABLE")
            {
                cout<<"Ця книга вже в бібліотеці."<<endl;
            }

            else 
            {
                cout<<"Дякуємо за повернення"<<endl;
                status[number-1]="AVAILABLE";
            }
            cout<<endl;
        }

        else if (action == 4)
        {
            cout<<endl<<"Приходьте ще!";

            break;
        }

        else
        {
            goto main_menu;
        }
        
        int z;
        
        do
        {   
            cout << "Хочете продовжити роботу в менеджменті бібліотеки? Введіть цифру 1 для продовження роботи або цифру 2 для завершення роботи."<<endl<<endl;
            cin>>z;

            if (z == 2)
            {   
                cout<<"Приходьте ще!";
                return 0;
            }
            else 
            {
                break;
            }
        } 
        while (z == 1);
    }
    return 0;
}