#include <iostream>                                                                               
using namespace std;            //інклудим модуль потоку вводу/виводу і неймспейс стд щоб не писати std::

int main()
{
    float price;        //ініціалізую змінні
    int choice;
    cout<<"(1/2) Enter price is by 100g(1) or by kg(2): ";  /*прошу користувача вибрати як буде вводитись ціна - в грамах або в кілограмах,
                                                            а потім зчитую ввід*/
    
    cin>>choice;
    if(choice != 1 && choice !=2)     //передбачаю неправильний ввід данних
    {
        cout<<"You entered wrong answer :(";
        exit(-1);
    }
    cout<<"Enter price: ";      //прошу користувача ввести ціну
    cin>>price;
    
    for(int i =100;i<=1000;i+=100)  // від 100г до кг з кроком 100г
    {  
        if (choice==1)
        {
            cout<<"The price for "<<i<<"g is: "<<price * (i/100.0) <<endl; 
        }
        else
        {
            cout<<"The price for "<<i<<"g is: "<<price * (i/1000.0)  <<endl; //якщо вибір 1 ділю ітератор на 100,інакше - на 1000
        }        
    }

}