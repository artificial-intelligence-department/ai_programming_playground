#include <iostream>

#include <stdarg.h>
using namespace std;

int min(int count, ...) {
    va_list list;
    va_start(list, count);
    int min = va_arg(list, int);
    for (int i = 0; i < count-1; ++i) {
        int current = va_arg(list, int);
        if (current < min){
            min = current;
        }
    }

    va_end(list);
    return min;
}

double min_d(int count, ...) {
    va_list list;
    va_start(list, count);
    double min = va_arg(list, int);
    for (int i = 0; i < count-1; ++i) {
        double current = va_arg(list, double);
        if (current < min){
            min = current;
        }
    }

    va_end(list);
    return min;
}



int main ()
{
    cout <<"Five: "<< min_d(5, 0.7, 0.5, 0.6,0.9, 0.10 )<<endl;
    cout <<"Five: "<< min(5, 7, 5, 6,9, 10 )<<endl;
    cout <<"Ten: "<< min(10, 72, 93, 67,95, 102,75,85,87,94,73 )<<endl;
    cout <<"Twelve: "<< min(12, 72, 93, 100,95, 102,75,85,87,94,73,96,78 )<<endl;
    return 0;
}
