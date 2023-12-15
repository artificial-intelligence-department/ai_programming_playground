#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned long a, b, c, d;                 // довжина ніжок столу
    unsigned long q1, q2, q3, q4;             // довжина розрізу ніжки
    unsigned long diff1, diff2, diff3, diff4; // різниця
    cout << "Вкажіть довжину ніжок столу\n";
    cin >> a >> b >> c >> d;
    cout << "Вкажіть довжину розрізу 1 ніжки столу\n";
    cin >> q1;
    cout << "Вкажіть довжину розрізу 2 ніжки столу\n";
    cin >> q2;
    cout << "Вкажіть довжину розрізу 3 ніжки столу\n";
    cin >> q3;
    cout << "Вкажіть довжину розрізу 4 ніжки столу\n";
    cin >> q4;

    const unsigned long i = 3;

    if (a < q1 or b < q2 or c < q3 or d < q4)
    {
        cout << ("ERROR"); // у випадку якщо ви відпиляєте більшу довжину ніж має ножка
    }
    else if (a - q1 >= 2 * min(min(b, c), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b), max(c, d)) >= 2 * min(min(b, c), min(a - q1, d))) // max>=2min
    {
        cout << "NO";
    }
    else if (b - q2 >= 2 * min(min(a - q1, c), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c, d)) >= 2 * min(min(a - q1, c), min(b - q2, d)))
    {
        cout << "NO";
    }
    else if (c - q3 >= 2 * min(min(a - q1, b - q2), d))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c - q3, d)) >= 2 * min(min(a - q1, c - q3), min(b - q2, d)))
    {
        cout << "NO";
    }
    else if (d - q4 >= 2 * min(min(a - q1, b - q2), c - q3))
    {
        cout << "NO";
    }
    else if (max(max(a - q1, b - q2), max(c - q3, d - q4)) >= 2 * min(min(a - q1, c - q3), min(b - q2, d - q4)))
    {
        cout << "NO";
    }
    else
    {
        cout << "YES";
    }
    return (0);
}
{
int a;
switch (a)

case 1 /* constant-expression */:
{
    cout << "ddd";
}
    /* code */
case 2 /* constant-expression */:
{
    cout << "ddd";
}

break;

default:
    break;
}