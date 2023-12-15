
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
    const double precision {0.0001}, e {2.71828},a{0.1},b{1};
    double sum{0};
    double n{0};
    int itterN {30};
    int k {0};
    for (double x = a; x <= b; x+=(b-a)/10)
    {
        do{
        if(k==0){
            // n= 7*sqrt(e)/4;
            n=1;
        }
        if(k==1){
            // n= 15*sqrt(e)/8;
            n=pow(x,k);
        }
        if(k>=2){
            n= pow(2,-k)*(1/tgamma(-2+k)+1/tgamma(-1+k)+1/tgamma(k))*pow(x,k);
        }
        
        sum += n  ;

        k +=1;

    }
    while (n>=precision);
     cout<<"X" << x<<" ";
    cout<<"SE" << sum<<" ";
    sum = 0;
    k=0;
    for (size_t i = 0; i < itterN; i++)
        {
        if(k==0){
            // n= 7*sqrt(e)/4;
            n=1;
        }
        if(k==1){
            // n= 15*sqrt(e)/8;
            n=pow(x,k);
        }
        if(k>=2){
            n= pow(2,-k)*(1/tgamma(-2+k)+1/tgamma(-1+k)+1/tgamma(k))*pow(x,k);
        }
        
        sum += n;

        k +=1;

    }

    cout<<"SN" << sum<<" ";
    sum = 0;
    k=0;
    cout<<"Y:" << (pow(x,2)/4+x/2+1)*pow(e,x/2)<<endl;
    
    }
    

    
    
    


    return 0;
}
