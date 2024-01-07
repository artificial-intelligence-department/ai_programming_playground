#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a,b,c; //Оголошення змінних для визначення величини 3-ьох сторін трикутника
    
    cout<<"Enter the 1st side value: "; //Почерговий ввід змінних
    cin>>a;
    cout<<"Enter the 2nd side value: ";
    cin>>b;
    cout<<"Enter the 3rd side value: ";
    cin>>c;

    double p = (a+b+c)/2; //Обчислення півпериметра трикутника

    //Обрахування та вивід висот, проведених з кожних заданих сторін
    cout<< "\nThe heigh to 1st side is: " <<2/a*(sqrt(p*(p-a)*(p-b)*(p-c)));
    cout<< "\nThe heigh to 2nd side is: " <<2/b*(sqrt(p*(p-a)*(p-b)*(p-c)));
    cout<< "\nThe heigh to 3rd side is: " <<2/c*(sqrt(p*(p-a)*(p-b)*(p-c)));

    return 0;
}