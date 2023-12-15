#include <iostream>
using namespace std;
int main()
{
    long q1, q2, q3, q4, q5;
    cout << "Введіть сторони 5 кубиків\n";
    cin >> q1 >> q2 >> q3 >> q4 >> q5;

    if (q1 < q2 or q2 < q3 or q3 < q4 or q4 < q5)
    {
        cout << ("LOSS\n"); // якщо один куб більший за інший
    }
    else if (q1 <= 0 or q2 <= 0 or q3 <= 0 or q4 <= 0 or q5 <= 0)
    {
        cout << ("ERROR\n"); // якщо куб менше рівне 0
    }
    else
    {
        cout << ("WIN\n"); // якщо не виконуються попередні умови
    }
    return (0);
}