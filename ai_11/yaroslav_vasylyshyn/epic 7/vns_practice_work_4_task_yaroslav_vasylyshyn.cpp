#include <iostream>
//variant 10
int main(){
    int n,factorial=1;
    std::cin>>n;
    for (int i = 1; i < n; i++)
    {
        factorial *= i;
    }
    std::cout<<"Factorial "<<n<<" is: "<<factorial;
}