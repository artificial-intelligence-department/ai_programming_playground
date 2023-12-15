#include <iostream>
#include <cmath>
#include <stdarg.h>
using namespace std;

// Microfunction for the circle;

int circle(double x, double y, double R)
{
    int func=sqrt(pow(x,2)+pow(y,2));
    return func <= R;
}

// Function that determines whether point belongs to the circle;

int belong(int R,int n, ...)
{
 int cnt =0;
    va_list arguments;
    va_start(arguments, n);

    for (int i = 0; i < n; i++) {

        int x = va_arg(arguments, int);

        int y = va_arg(arguments, int);

        if (circle(x, y, R)) {
            cnt++;
        }
    }

    va_end(arguments);

    return cnt;


}

int main()
{
    int Case_1= belong(30 ,3, 0,2, 4,6, 8,10);
    int Case_2= belong(30 ,9, 1,2 ,3,4, 5,6, 7,8, 9,10, 11,12, 13,14, 22,25, 30,30 );
    int Case_3= belong(30 ,11, 1,1, 2,2, 3,3, 4,4, 5,5, 6,6, 7,7, 8,8, 9,9, 10,10, 25,25);
    cout<<"VNS lab 7 "<<endl;
    cout<<"Variant 19"<<endl;
    cout<<"Task 1 "<<endl;
    cout<<"Number of points that belong to the circle with 3 parametrs:"<<Case_1<<endl;
    cout<<"Number of points that belong to the circle with 9 parametrs:"<<Case_2<<endl;
    cout<<"Number of points that belong to the circle with 11 parametrs:"<<Case_3<<endl;
}