#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;

vector<int> decToOct(int num_args, ...){
    va_list args;
    va_start (args, num_args);
    vector<int> octnums;
    for(int i = 0; i < num_args; i++){
        int decnum = va_arg(args, int);
        int octalnum = 0, a = 1, rem;
         while (decnum != 0) {
            rem = decnum % 8;
            decnum /= 8;    
            octalnum += rem * a;
            a *= 10;
        }
        octnums.push_back(octalnum);

    }
        
    va_end(args);
    return octnums;
}

int main(){

   vector<int> result1 =  decToOct(3, 20, 60, 70);
   vector<int> result2 =  decToOct(5, 24, 65, 78, 25, 21);
   vector<int> result3 =  decToOct(8, 34, 75, 58, 45, 91, 11, 56, 17);
    for (int octal : result1) {
        std::cout << octal << " ";
    }
    std::cout << endl;
    for (int octal : result2) {
            std::cout << octal << " ";
        }
    std::cout << endl;
    for (int octal : result3) {
        std::cout << octal << " ";
    }
    std::cout << endl;
    return 0;
}