#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    cout << "Введіть довжину ребра (см) та натисніть клавішу <Enter>" << endl;
    double a;
    cin >> a;
    double V = pow(a, 3);
    double roundedValue = round(V * 100.0) / 100.0;
    cout << "Об'єм куба: " << fixed << setprecision(2) << roundedValue << endl;
}