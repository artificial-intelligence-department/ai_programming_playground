#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    // Обчислення об'єму куба
    // Вимога 1 цілочисельна змінна
    // Вимога 2 дійсна змінна
    int a;
    double s;
    cout << "Type in cube side lenght" << endl;
    cin >> a;
    if (a <= 0)
    {

        cerr << "ERROR" << endl;

        return 0;
    }
    s = pow(a, 3);
    cout << "volume of the cube is:  " << s << endl;

    // Обчислення площі трапеції

    double A, B, h;
    double S;
    cout << "_______________________________" << endl;
    cout << " " << endl;
    cout << "Type in trapezoid bases (a, b):" << endl;
    cin >> A >> B;
    // Вимога 5 умовні оператори та розгалуження
    if (A <= 0 || B <= 0)
    {

        cerr << "ERROR" << endl;
        return 0;
    }
    cout << "Type in trapezoid height:" << endl;
    cin >> h;
    if (h <= 0)
    {

        cerr << "ERROR" << endl;
        return 0;
    }
    else
    {

        S = (((A + B) * h) / 2);
        cout << "The trapezoid square equals:  " << S << endl;
    }
    return 0;
}