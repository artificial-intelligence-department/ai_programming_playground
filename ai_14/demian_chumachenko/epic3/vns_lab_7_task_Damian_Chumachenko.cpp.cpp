#include <iostream>
#include <cmath>

using namespace std;

void eight_to_ten(int k, ...){

    int *p = &k; 
    int num, bit, n, value;
    for( ; k!=0; k--){
        n = 0;
        value = 0;
        p+=2;
        num = *p;
        while(num != 0){
            bit = num % 10;
            value += bit*pow(8, n);
            n++;
            num /= 10;
        }
        cout << value << " ";
    }
    cout << endl;
}
int main(){
    eight_to_ten(3,347, 2,3);
    eight_to_ten(6,77, 66, 55, 44, 33, 22);
    eight_to_ten(7,34, 24, 36, 765, 543, 21, 19);
    return 0;
}