#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
    //Оголошення та ініціалізація змінних
    double n=30,y,elem,k=10,e=0.0001,sume=0,sumr=0,sumn=0;
    //Розрахунок
    for (double  x = 0.1; x < 1; x += ((1-0.1)/k))
    {
        cout<<"X = ";
        printf("%.3lf",x);
        cout<<"    ";
        //Знаходження за кількістю елементів
        for (int i = 1; i <= n; i++)
        {
            sumn += ((pow((-1),i+1))*(pow(x, 2*i + 1))/(4*i*i-1));
        }
        cout<<"SN = ";
        printf("%.6lf",sumn);
        cout<<"\t";
        sumn=0;
        //Знаходження з точністю до 0.0001
        elem=pow(x, 3)/3;
        n=2;
        while(abs(elem) > 0.0001)
        {
            sume += elem;
            elem = ((pow((-1),n+1))*(pow(x, 2*n + 1))/(4*n*n-1));
            n++;
        }
        cout<<"SE = ";
        printf("%.5lf",sume);
        cout<<"\t";
        sume=0;
        //точне значення
        y=(((1+x*x)/2)*atan(x)-(x/2));
        cout<<"Y = ";
        printf("%.5lf", y);
        cout<<"\n";
    }
    return 0;
}