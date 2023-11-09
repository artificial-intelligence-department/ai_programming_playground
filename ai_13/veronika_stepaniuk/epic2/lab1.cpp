#include<iostream>
#include<Windows.h>
#include<stdio.h>
#define _USE_MATH_DEFINES
#include<cmath>


int main()
{
    unsigned long long int h1, h2, h3, h4, d1, d2, d3, d4;
    std::cout<<"Enter the length of the table legs\n";
    std::cin>>h1;
    std::cin>>h2;
    std::cin>>h3;
    std::cin>>h4;
    std::cout<<"Enter the length to be sawed off from the corresponding leg\n";
    std::cin>>d1;
    std::cin>>d2;
    std::cin>>d3;
    std::cin>>d4;
    if(d1>h1||d2>h2||d3>h3||d4>h4)
    {std::cout<<"ERROR";
    return 0;}
    unsigned long long int minleg=h1;
    unsigned long long int maxleg=h1;
    if(h2<minleg)
    minleg=h2;
    else if(h2>maxleg)
    maxleg=h2;
    if(h3<minleg)
    minleg=h3;
    else if(h3>maxleg)
    maxleg=h3;
    if(h4<minleg)
    minleg=h4;
    else if(h4>maxleg)
    maxleg=h4;
    int perevorot=0;

    h1=h1-d1;
    if(h1<minleg)
    {minleg=h1;
    if(maxleg>=2*minleg)
    perevorot++;}
    else if(h1>maxleg)
    {maxleg=h1;
    if(maxleg>=2*minleg)
    perevorot++;}

    h2=h2-d2;
    if(h2<minleg)
    {minleg=h2;
    if(maxleg>=2*minleg)
    perevorot++;}
    else if(h2>maxleg)
    {maxleg=h2;
    if(maxleg>=2*minleg)
    perevorot++;}

    h3=h3-d3;
    if(h3<minleg)
    {minleg=h3;
    if(maxleg>=2*minleg)
    perevorot++;}
    else if(h3>maxleg)
    {maxleg=h3;
    if(maxleg>=2*minleg)
    perevorot++;}

    h4=h4-d4;
    if(h4<minleg)
    {minleg=h4;
    if(maxleg>=2*minleg)
    perevorot++;}
    else if(h4>maxleg)
    {maxleg=h4;
    if(maxleg>=2*minleg)
    perevorot++;}

    if(h1!=0&&h2!=0&&h3!=0&&h4!=0&&h1/h2==h3/h4&&h1/h3==h2/h4&&perevorot==0)
    std::cout<<"YES";
    else
    std::cout<<"NO";

    
    return 0;
}