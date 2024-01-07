#include <iostream>

using namespace std;
//Вимога 14. в коді використано структури 
struct Parallelepiped
{
    double leth,width,high;
};


int main()
{
//Вимога 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    Parallelepiped p;

// Вимога 21. в коді використано оператори виведення та введення даних
    cout << "Enter leth of parallelepiped: ";
    cin >> p.leth;

    cout << "Enter width of parallelepiped: ";
    cin >> p.width;

    cout << "Enter high of parallelepiped: ";
    cin >> p.high;
//Вимога 3. в коді використана як мінімум одна дійсний з подвійною точністю змінна
    double area;
    
//Вимога 17. в коді використано математичні операції та математичні функції
    area = 2 * (p.leth * p.width + p.leth * p.high + p.width * p.high);

//Вимога 5. в коді використані умовні оператори та розгалуження
    
    if(area < 0)
    {
        cout << "area can't be native" << endl;
       
    }
    else
    {
        cout <<"surface area of a parallelepiped "  << area <<" square cm"<< endl;
    }

    return 0;
}