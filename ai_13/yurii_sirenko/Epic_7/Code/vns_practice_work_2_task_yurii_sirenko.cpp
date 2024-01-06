#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double e = 2.71828; //Визначення константи Ейлера
    int count=0;    // Оголошення змінної для обрахунку кількості разів,
    int gen=0;      // коли функція перебуває у від'ємних значеннях
    for(double x = 0.3;x<=5;x+=0.1) //Оголошення ітеративного циклу 
    {                               //з кроком для x який дорівнює 0.1
        if(cos(pow(x,2))*pow(e,-x)<0)   //Якщо знаходимо, що обчислене 
        {                               //значення є від'ємним,
            count++;                //то додаєм одиницю до нашого рахунку
        }
        gen++;
    }
    //Виводим результат обрахунку
    cout<<"The function goes through graph "<<gen<<" times,\n" 
        <<"and takes negative value "<<count<<" times";    

    return 0;
}