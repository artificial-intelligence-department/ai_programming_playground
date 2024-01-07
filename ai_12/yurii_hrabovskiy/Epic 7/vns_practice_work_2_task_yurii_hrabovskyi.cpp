#include<iostream>
#include<cmath>

using namespace std;

double high_of_triangle(double a, double b, double c)
{
    double p, high;
    p=(a+b+c)/2;
    high=2/a*sqrt(p*(p-a)*(p-b)*(p-c));
    return high;
}

int main()
{ 
    double a, b, c, max_high=0;
    
    for(int i=0; i<5; i++)
    {
        cout<<"Введіть сторони трикутника"<<endl;
        cin>>a>>b>>c;
       
        if (high_of_triangle(a, b, c)>=max_high)
            max_high=high_of_triangle(a, b, c);
    }

    cout<<max_high;
    return 0;
}
