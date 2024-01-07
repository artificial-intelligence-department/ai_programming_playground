#include <iostream>
#include <math.h>

int main()
{
    long double X=0.1, Y;

    while (X<=1)
    {
        std::cout<<"X="<<X<<"    ";

        long double SN=1, a1=1;
        int n1=1;
        while (n1<=20)
        {
            a1=a1*2*X/n1;
            SN=SN+a1;
            n1=n1+1;
        }
        std::cout<<"SN="<<SN<<"    ";


        long double SE=1, a2=1; 
        int n2=1;
        while (a2>=0.0001)
        {
            a2=a2*2*X/n2;
            SE=SE+a2;
            n2=n2+1;
        }
        std::cout<<"SE="<<SE<<"    ";
    
        
        Y=pow(M_E,2*X);
        std::cout<<"Y="<<Y<<std::endl;
        X=X+(1-0.1)/10;
    }

    return 0;
}