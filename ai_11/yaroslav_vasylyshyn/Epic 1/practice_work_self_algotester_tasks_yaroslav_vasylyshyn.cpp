#include <iostream>
#include <math.h>
using namespace std;
int main() {
    float r,n,radmin;
    cin>>n>>r;
    radmin=sqrt((r*r)/(n));
    cout<<'\n'<<radmin;
    return 0;
}
