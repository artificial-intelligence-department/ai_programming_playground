#include <iostream>
 #include <cmath>
 using namespace std;
 double factorial(int n){ // функція яка виконує роль факторіала
     double factorial = 1;
     for (int i = 0; i < n; i++){
         factorial*=(i + 1); 
     }
     return factorial;
 }

 int main(){
     const double e = 2.71828;

     for (double x = 0.1; x <= 1; x += 0.1){
         double Se = 0, Sn = 0, y;
         y = pow(e, cos(x)) * cos(sin(x)); // знаходження y
         for (int n = 0; n <= 20; n++){  //значення суми для заданого n;
             Sn += cos(n*x) / factorial(n);
         }
         int m = 0;

         cout << "x = " << x << " Sn = " << Sn << " y = " << y << endl;
     }
     
     return 0;
 }