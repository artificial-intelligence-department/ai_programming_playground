#include <iostream>
#include <cstdarg>
using namespace std;


double sum (int k, ...) {
    
    va_list elements;
    va_start(elements,k);
    double ssum = 0;

    for (int i=0; i<k; i++) {
        ssum += va_arg(elements, double);
    }

    va_end(elements);
    return ssum;

}

int main () {

    cout << "Sum of 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10 = " << sum (5, 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10) << endl;
    cout << "Sum of 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10, 6.0/12, 7.0/14, 8.0/16, 9.0/18, 10.0/20 = " << sum (10, 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10, 6.0/12, 7.0/14, 8.0/16, 9.0/18, 10.0/20) << endl;
    cout << "Sum of 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10, 6.0/12, 7.0/14, 8.0/16, 9.0/18, 10.0/20, 11.0/22, 12.0/24 = " << sum (12, 1.0/2, 2.0/4, 3.0/6, 4.0/8, 5.0/10, 6.0/12, 7.0/14, 8.0/16, 9.0/18, 10.0/20, 11.0/22, 12.0/24) << endl;
    
    return 0;
}