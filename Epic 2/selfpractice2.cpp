#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c, d, e, f;

    cout << "Алгебра та геометрія: ";
    cin >> a;
    cout << "Математичний аналіз: ";
    cin >> b;
    cout << "Програмування: ";
    cin >> c;
    cout << "Історія України: ";
    cin >> d;
    cout << "Іноземна мова: ";
    cin >> e;
    cout << "Архітектура ком'ютера: ";
    cin >> f;

    float result = (a + b + c + d + e + f) / 6;
    cout << result << endl;

if (result >= 88 && result <= 100) 
    cout << "Відмінно" << endl;
 else if (result >= 71 && result <= 87)
    cout << "Добре" << endl;
 else if (result >= 50 && result <= 70)
    cout << "Задовільно" << endl;
 else if (result >= 26 && result <= 49)
    cout << "Неатестований" << endl;
 else if (result >= 0 && result <= 25)
    cout << "Незадовільно" << endl;
 else 
    cout << "  " << endl;
    return 0;
}