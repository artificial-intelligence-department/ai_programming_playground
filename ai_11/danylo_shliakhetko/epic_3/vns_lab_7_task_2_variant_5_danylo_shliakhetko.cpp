#include <iostream>
using namespace std;

void multiply(double a, double b);
void multiply(double ax, double ay, double bx, double by);

int main()
{
    int a, b, imaginaryA, imaginaryB;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter imaginary a: ";
    cin >> imaginaryA;
    cout << "Enter imaginary b: ";
    cin >> imaginaryB;

    multiply(a, b);
    multiply(a, imaginaryA, b, imaginaryB);
    
    return 0;
}

void multiply(double a, double b)
{
    cout << a * b << "\n";
    return;
}

void multiply(double ax, double ay, double bx, double by)
{
    cout << ax * bx << " + " << ay * by << "i" << "\n";
    return;
}