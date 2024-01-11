#include <iostream>
#include <cmath>

using namespace std;

void convertToHoursAndMinutes(int minutes, int &hours, int &remainingMinutes) {
    hours = minutes / 60;
    remainingMinutes = minutes % 60;
}

double calculateTriangleArea(double angle1, double angle2, double angle3) {
    const double PI = 3.14159265358979323846;
    double a = 5.0;
    double b = 7.0;

    double c = sqrt(a*a + b*b - 2*a*b*cos(angle3 * (PI / 180.0)));

    return 0.5 * a * b * sin(angle3 * (PI / 180.0));
}

int main() {
    int minutes = 150;
    double angle1 = 30.0;
    double angle2 = 60.0;
    double angle3 = 90.0;

    int hours, remainingMinutes;
    convertToHoursAndMinutes(minutes, hours, remainingMinutes);
    cout << minutes << " хвилин - це " << hours << " год. " << remainingMinutes << " хв." << endl;

    double triangleArea = calculateTriangleArea(angle1, angle2, angle3);
    cout << "Площа трикутника: " << triangleArea << endl;

    return 0;
}
