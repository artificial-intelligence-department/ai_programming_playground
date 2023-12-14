#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //ініціалізуємо змінні
   double x=0.25, y=0.79, z=0.81, P, Q;

   // Розрахунок виразу P
   P = ((1+pow(sin(x+1),2))/(2+(abs(x-2*x*x*x))/(1+x*x*y*y*y)))+pow(x,4);

   //  Розрахунок виразу Q
   Q = pow(cos(atan(1/z)),2);

   //Виведення результатів на екран
   cout<<P<<endl;
   cout<<Q<<endl;
        return 0;
    }