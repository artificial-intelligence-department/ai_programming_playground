#include <iostream>
using namespace std;

int main() {
    double length, width, height;

    cout << "Введіть довжину (см): ";
    cin >> length;

    cout << "Введіть ширину (см): ";
    cin >> width;

    cout << "Введіть висоту (см): ";
    cin >> height;

    double surface_area = 2 * (length * width + length * height + width * height);
    cout << "Площа поверхні: " << surface_area << " кв.см." << endl;

    double kilometers;
    const double meters_in_verst = 1066.8;
    cout << "Введіть кількість кілометрів: ";
    cin >> kilometers;

    double versts = kilometers * 1000 / meters_in_verst;
    cout << kilometers << " км дорівнює " << versts << " верстам." << endl;

    return 0;
}
