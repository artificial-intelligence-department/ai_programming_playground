#include <iostream>
#include <math.h>
int main(){
    int n, x1, x2, y1, y2;
    int s=0;
    std::cin>>n;
    while (n!=0){
        std::cin>>x1>>y1>>x2>>y2;
        s=s+pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
        n=n-1;}
    std::cout<<s;

    return 0;
    }