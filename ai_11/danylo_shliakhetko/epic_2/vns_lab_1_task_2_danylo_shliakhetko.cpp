#include <iostream>
#include <math.h>
using namespace std;

void floatMethod();
float floatCondition1(float n, float m);
bool floatCondition2(float n, float m);
bool floatCondition3(float n, float m);

void doubleMethod();
double doubleCondition1(double n, double m);
bool doubleCondition2(double n, double m);
bool doubleCondition3(double n, double m);

int main()
{
    cout << boolalpha;
    floatMethod();
    doubleMethod();
    return 0;
}

void floatMethod()
{
    cout << "--- Float Method ---\n";
    double n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    cout << "n++-m: " << floatCondition1(n, m) << "\n";
    cout << "m-->n: " << floatCondition2(n, m) << "\n";
    cout << "n-->m: " << floatCondition3(n, m) << "\n";
}

void doubleMethod()
{
    cout << "--- Double Method ---\n";
    double n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;
    cout << "n++-m: " << doubleCondition1(n, m) << "\n";
    cout << "m-->n: " << doubleCondition2(n, m) << "\n";
    cout << "n-->m: " << doubleCondition3(n, m) << "\n";
}

float floatCondition1(float n, float m)
{
    return n++ - m;
}

bool floatCondition2(float n, float m)
{
    return m-- > n;
}

bool floatCondition3(float n, float m)
{
    return n-- > m;
}

double doubleCondition1(double n, double m)
{
    return n++ - m;
}

bool doubleCondition2(double n, double m)
{
    return m-- > n;
}

bool doubleCondition3(double n, double m)
{
    return n-- > m;
}
