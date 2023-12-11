#include <iostream>
#include <string>

using namespace std;

int main()
{
    //Оголошення змінної типу string для більшої мобільності в операціях з вводом даних 
    string number;
    cout<<"Enter the positive numbers, and type -result-, the program\nwill count it's sum and average value: \n";
    //Оголошення змінних суми та рахунку
    double sum = 0,count = 0;
    //Оголошення циклу з умовою введення result в консоль для його завершення 
    while(true)
    {
        //Зчитування числа з консолі
        cin>>number;
        if(number=="result")
        {break;}
        //Якщо це число, то виконується зміна типу даних
        sum+=stoi(number);
        //Та додається 1 до нашого лічильника
        count++;
    }
    //Вивід суми та середнього значення чисел 
    cout<<"Sum of inputed numbers is: "<<sum<<"\n";
    cout<<"Average value of inputed numbers is: "<<sum/count<<"\n";

    return 0;
}