#include <iostream>
#include <cmath>

using namespace std; 

int main(){
    int sum = 0; //Лічильник

    for(int n = 1;n <= 7; n++){
        sum += pow(n,2) * exp(-sqrt(n));
    }
    cout << "The sum of the first 7 members of the series: " << sum << endl;
    return 0;
}