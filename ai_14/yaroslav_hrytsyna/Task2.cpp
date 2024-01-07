#include <iostream>
#include <cmath>
using namespace std;
//змінні дробові
float x,z,y;
int main(){
    //ввід
    cout<<"Введіть х від -2,5 до 2: ";
    cin >> x;
    //перевірка правильності введених даних
    if (x!=-2 && x>=-2.5 && x<=2){
        //формула
        z=abs(x)+x*x;
        y=z*sin(pow(2+x,2))/(2+x);
        //вивід
        cout<<y;
    }
    else{
        //вивід про неправильність даних
        cout << "Неправильний ввід";
    }
}