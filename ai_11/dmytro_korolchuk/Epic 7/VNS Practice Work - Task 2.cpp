#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double z, hx, a; //задаємо тип змінних
    a=2.4;//задаємо значення змінних
    hx=0.5;
    for(double x = -3; x<=3; x+=hx){//цикл для проходження по діапазону х
        z=(pow(a,x)*log(abs(x+2*2*2)))/(x+1);//обчислюємо значення виразу 
        cout<<z<<endl;//виводимо результат
    }
}