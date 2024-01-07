// 10 Варіант
#include <iostream>
#include <string>
#include <cmath>

    using namespace std;

    int main()
{
    // додання дійсних змінних
    double x;
    double y;
    double z;
    double a,b,c;
    double a1,a2;
    // додання константи
    const double e = 2.71828; 

    // введення даних в змінні
    cin >> x; 
    cin >> y;
    cin >> z;

    // обчислення змінної a
    a1= sqrt(abs(x-1))-sqrt(y);
    a2 = 1+((pow(x,2))/2)+((pow(x,2))/4);
    a=a1/a2;

    // обчислення змінної b
    b = 1/(tan(pow(e,x+3)));

    // вивід даних
    cout <<a<<endl;
    cout <<b<<endl;

    return 0;
}
