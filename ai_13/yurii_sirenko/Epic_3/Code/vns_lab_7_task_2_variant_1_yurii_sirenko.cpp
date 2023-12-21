#include <iostream>
#include <cmath>

using namespace std;
struct complex
{
    int real;
    int imaginary;
};

int sum(int a,int b)
{
    return(a+b);
}
complex sum(complex a,complex b)
{
    complex result;
    result.real=a.real+b.real;
    result.imaginary=a.imaginary+b.imaginary;
    return result;
}

int main()
{
    string answer;
    cout<<"Enter, what type of number you want to add:\n1) real\n2) complex\n";
    cin>>answer;
    if(answer=="real")
    {
        int x,y;
        cout<<"Enter numbers you want to add:\n";
        cin>>x>>y;

        cout<<"Sum = "<<sum(x,y)<<"\n";
    }
    else if(answer=="complex")
    {
        int x,xi,y,yi;
        cout <<"Enter values in real and imaginary world for 2 numbers\n";
        cin>>x>>xi>>y>>yi;

        complex c1={x, xi};
        complex c2={y, yi};
        complex complexsum = sum(c1,c2);
        cout<<"Complex sum = "<<complexsum.real<< " + "<<complexsum.imaginary<<"i\n";

    }

    return 0;
}