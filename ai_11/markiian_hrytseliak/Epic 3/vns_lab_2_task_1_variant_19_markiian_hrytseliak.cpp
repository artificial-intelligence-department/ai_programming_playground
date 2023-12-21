#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double eps= 0.0001;// If the value of a is lower than 0.0001, we stop the cycle
    double s= 0.0;// Initial value of sum
    double a= 0.0; //initial value of a member
    int n = 2; // Initial value of n , because (n-1)!= 0

    do
    {
        a= n/pow((n-1),2);// The formula of the common member
        s += a;// we add every member to the sum
        n++;// we increase the value of n by 1 with every cycle
    }
    while( a >= e);//The cycle repeats, until the value of a will be lower than 0.0001
        cout<<"Variant 19"<<endl;
        cout<<"The sum of a range with precision to "<<eps<<" is equal: "<<s<< endl;
    return 0;
}

