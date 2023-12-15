#include <iostream>
#include <cstdarg>
using namespace std;

int days(int a, ...) {
    va_list args;
    va_start(args, a);

     char* number_1 = va_arg(args,  char*);
     char* number_2 = va_arg(args,  char*);

        int year = number_1[6] * 10 + number_1[7];
        int year1 = number_2[6] * 10 + number_2[7];

        int month =number_1[3]  * 10 + number_1[4];
        int month1 = number_2[3] * 10 + number_2[4];

        int day = number_1[0] * 10 + number_1[1];
        int day1 = number_2[0] * 10 + number_2[1];


        int years = 365;
        years *= year1 - year;

        int months = 30;
        months *= month1-month;
        
        int days1 = day1 - day;

        int suma = years + months + days1;

        cout << suma <<endl;

    va_end(args);
    return 0;
}

int main() {
    cout<<"1.";
    days(3, "15.08.23", "15.09.23", "25.01.23");
    cout<<"2.";
    days(5, "18.02.19", "20.02.20", "21.10.21", "24.10.22", "19.08.23");
    cout<<"3.";
    days(8, "01.03.16", "05.03.23", "08.04.23", "10.04.23", "20.05.23", "01.06.23", "10.03.24", "31.05.24");

    return 0;
}