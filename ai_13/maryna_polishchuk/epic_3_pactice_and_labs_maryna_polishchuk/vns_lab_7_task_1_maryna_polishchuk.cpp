#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
#define pi 3.1415926535
#define FIND_ANGLE_1(a,b,c) acos(-(a*a-b*b-c*c) / (2.0*b*c)) * (180/pi)
#define FIND_ANGLE_2(a,b,c) acos(-0.5 * (b*b-a*a-c*c) / (a*c)) * (180/pi)
#define FIND_ANGLE_3(a,b,c) acos(-(c*c-a*a-b*b) / (2.0*a*b)) * (180/pi)
double angles(double firstSide, ...)
{
    va_list args;
    va_start(args, firstSide);
    int count = 1;
    while (va_arg(args, int) != 0) {
        count++;
    }
    double angle = (180 * (count-2)) / count;
    return angle;
}
int main()
{
    int a = 3, b = 4, c = 5;
    if(a+b>c && a+c>b && b+c>a)
    {
        cout << "angle1 = " << FIND_ANGLE_1(a,b,c) << endl;
        cout << "angle2 = " << FIND_ANGLE_2(a,b,c) << endl;
        cout << "angle3 = " << FIND_ANGLE_3(a,b,c) << endl;
    }
    double angleOfFigure = angles(5, 5, 5, 0);
    cout << "angle of 3angle: " << angleOfFigure << endl;
    double angleOfFigure2 = angles(5, 5, 5, 5, 5, 5, 5, 5, 5, 0);
    cout << "angle of 9angle: " << angleOfFigure2 << endl;
    double angleOfFigure3 = angles(5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0);
    cout << "angleof 11angle: " << angleOfFigure3 << endl;
}