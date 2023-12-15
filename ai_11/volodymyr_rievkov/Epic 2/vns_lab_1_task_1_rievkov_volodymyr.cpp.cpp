#include<iostream>
#include<cmath>
using namespace std;

const float a1 = 1000;
const float b1 = 0.0001;
const double a2 = 1000;
const double b2 = 0.0001;

void PrintTask()
{
    cout << "-------------------------------" << endl;
    cout << "a: 1000" << endl;
    cout << "b: 0.0001" << endl;
    cout << "-------------------------------" << endl;
    cout << "(a+b)^2-(a^2+2ab)" << endl;
    cout << "—————————————————" << endl;
    cout << "       b^2       " << endl;
    cout << "-------------------------------" << endl;
}

void CountAndPrintFloatResult()
{
    float a = pow(a1 + b1, 2);
    cout << "First action: " << a << endl;
    float b = pow(a1, 2);
    cout << "Second action: " << b << endl;
    float c = 2 * a1 * b1;
    cout << "Third action: " << c << endl;
    float d = a - (b + c);
    cout << "Fourth action: " << d << endl;
    float e = pow(b1, 2);
    cout << "Fifth action: " << e << endl;
    float f = d / e;
    cout << "Float result: " << f << endl;
    cout << "-------------------------------" << endl;
}

void CountAndPrintDoubleResult()
{
    double a = pow(a2 + b2, 2);
    cout << "First action: " << a << endl;
    double b = pow(a2, 2);
    cout << "Second action: " << b << endl;
    double c = 2 * a2 * b2;
    cout << "Third action: " << c << endl;
    double d = a - (b + c);
    cout << "Fourth action: " << d << endl;
    double e = pow(b2, 2);
    cout << "Fifth action: " << e << endl;
    double f = d / e;
    cout << "Double result: " << f << endl;
    cout << "-------------------------------" << endl;
}

int main()
{
    PrintTask();
    CountAndPrintFloatResult();
    CountAndPrintDoubleResult();
}
