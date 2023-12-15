#include<iostream>

int main()
{
    int price,res=0;
    
    std::cin>>price;

    while(price>=500)
    {
        price-=500;
        res++;
    }
    while(price>=200)
    {
        price-=200;
        res++;
    }
    while(price>=100)
    {
        price-=100;
        res++;
    }
    while(price>=50)
    {
        price-=50;
        res++;
    }
    while(price>=20)
    {
        price-=20;
        res++;
    }
    while(price>=10)
    {
        price-=10;
        res++;
    }
    while(price>=5)
    {
        price-=5;
        res++;
    }
    while(price>=2)
    {
        price-=2;
        res++;
    }
    while(price>=1)
    {
        price-=1;
        res++;
    }

    std::cout<<res;
}