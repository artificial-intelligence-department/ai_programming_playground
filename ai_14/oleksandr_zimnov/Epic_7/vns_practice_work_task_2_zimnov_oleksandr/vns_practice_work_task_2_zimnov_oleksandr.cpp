#include <iostream> 
#include <cmath> 

using namespace std; 
int main() {
    double y=0; // a value of zero is set, as new values will be added in the future
    int x=3;
    for(int i=1; i<=10; i++){ // the loop for is used to find the values of functions, it is executed 10 times, starting from one and ending at 10
        y+=(pow(x,i))/i; // function pow use to display a number in degrees
    }
    cout<<"Sum of each function y="<<y;
}