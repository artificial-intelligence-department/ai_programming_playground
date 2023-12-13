#include <iostream>  //дозволяє використовувати виведення(cout) і введеня(cin)
#include <cmath>    //містить функції для математичних операцій
using namespace std;

int main(){
 double x, a, y; //задаю змінні типу double
    double s=1;
    for(double ix=1; ix<=8; ix+=0.5){ //використовую цикл for для пошуку всіх x в проміжку[1;8] 
        x=ix;
        for(int ia=2; ia<=10; ia++){ //використовую цикл for для пошуку всіх a в проміжку[2;10] 
            a=ia;
            if (a>x){ //використовую умовні оператори if-else для розв'язання математичної системи 
        y=pow(a, 2)+x;
    }else if(a<x){
        y=pow(a, 2)-x;
    }else if(a=x){
        y=pow(a, 2);
    }else;
        cout << " x = " << x << "  a = " << a << "  y = " << y << endl;} //через cout виводжу даний результат 
        }
        
return 0;
}