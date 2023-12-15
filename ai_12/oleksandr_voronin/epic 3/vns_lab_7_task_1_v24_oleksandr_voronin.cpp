#include <iostream>
#include <cmath>
#include <cstdarg>
using namespace std;
struct Point 
{
    double x, y;
};
double FindLength(double x1,double x2,double y1, double y2)
{

return sqrt(pow(x2 - x1,2)+pow(y2 - y1,2));
}

double square(double x1, double x2,double x3,double y1,double y2,double y3)
{
    //Shoelace formula
    double S = fabs((x1*y2+x2*y3+x3*y1)-(y1*x2+y2*x3+y3*x1))/2;
    return S;
}
//Створення змінної типу Point з кординатами x y
Point create(double x,double y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
double squarel(int n, ... )
{
va_list args;
va_start(args, n);
 Point  start = va_arg(args, Point),    
        current = start,                
        next;                           

    double S = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        next = va_arg(args, Point);
       
        S += current.x * next.y - next.x * current.y;
        current = next;
    }
    S += current.x * start.y - start.x * current.y;

    va_end(args);

    double Square = fabs(S) / 2;
    return Square;
}

int main()
{
cout << "the length of the points " << FindLength(5,4,7,3)<<endl;;
cout << "Square of triangle " <<square(3,2,3,1,3,3)<<endl;
cout << "Sixangles "<< squarel(6,
    create(3, 76),
    create(63, 9),
    create(23, -67),
    create(1, 0),
    create(56, 2),
    create(49 ,33)
    ) <<endl;
    cout << "10 angles "<< squarel(10,
    create(3, 76),
    create(63, 9),
    create(23, -67),
    create(1, 0),
    create(56, 2),
    create(49 ,33),
    create(49 ,5),
    create(5 ,-2),
    create(557 ,8),
    create(3 ,3)
    ) <<endl;
}