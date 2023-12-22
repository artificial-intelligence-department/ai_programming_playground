#include <iostream>

using namespace std;

int main()
{
    cout << "Amperage calculation. Enter voltage & resistance> ";
    float voltage = 36, resistance = 1500;
    cin >> voltage >> resistance;

    cout << "Amperage is " << voltage / resistance << endl;

    cout << "difference of expressions. enter a, b, c & d> ";
    float a = 2.1265123, b = 3.1116743, c = 1.5224222, d = 4.346372;
    cin >> a >> b >> c >> d;

    cout << (a * b) - (c * d);

    return 0;
}