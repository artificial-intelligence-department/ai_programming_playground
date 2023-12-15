#include <iostream>

int main()
{
    long long H, M;
    long long h1, m1;
    long long h2, m2;
    long long h3, m3;

    std::cin>>H>>M;
    std::cin>>h1>>m1;
    std::cin>>h2>>m2;
    std::cin>>h3>>m3;

    if(H<=0 || M<=0) {
        std::cout<<"NO";
        return 0;
    }if (h1>0 && m1>0) {
        std::cout<<"NO";
        return 0;
    }if (h2>0 && m2>0) {
        std::cout<<"NO";
        return 0;
    }if (h3>0 && m3>0) {
        std::cout<<"NO";
        return 0;
    } else if (H-h1-h2-h3>0 && M-m1-m2-m3>0) {
        std::cout<<"YES";
        return 0;
    } else {
        std::cout<<"NO";
        return 0;
    }
}