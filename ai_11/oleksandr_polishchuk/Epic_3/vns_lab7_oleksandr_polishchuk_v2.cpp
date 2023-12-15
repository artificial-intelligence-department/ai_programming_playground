#include <iostream>
#include <cmath>
#include <cstdarg>

using namespace std;

void prost(int number, ...)
{   
   
    
    va_list parameters;
    va_start (parameters, number);
    
    for (int x=0; x < number; x++)
        {
            int first=va_arg(parameters, int);
            int second=va_arg(parameters, int);
            for (int n=first; n<second; n++)
            {   
                bool isProst=true;
                for (int i=2; i <= sqrt(n); i++)
                    {
                        if (n%i==0)
                            { 
                                isProst=false;
                                break;
                            }
                    }
                        if(isProst==true)
                        {
                        cout << n << "\t";
                        }
            
                    
            }           
        
        }
        cout << "\n";
        
    va_end(parameters);
}

   int main()
{   
    prost(3, 1, 10, 16, 22, 23, 32);
    prost(5, 1, 10, 16, 22, 23, 32, 35, 40, 41, 52);
    prost(6, 1, 10, 16, 22, 23, 32, 35, 40, 41, 52, 55, 63);
    return 0;
}
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   


