#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    
  
    long long int an[5] {0};
    long long int prevCubeV {0};

   for (size_t i = 0; i < 5; i++)
   {
    // cout << "enter the length of the "<<i+1<<"  cube:"<<endl;
    cin>> an[i];
    
    if(an[i] <= 0 || an[i] <= -pow(10, 12) || an[i] >= pow(10, 12)){
            cout << "ERROR"<< endl;
            return 0;
        }

    long long int cubeV = pow(an[i],3);
        // cout << i+1 << " cube:" << cubeV<< endl;

        if (i == 0) {
        
            prevCubeV = cubeV;
        }
        
        
        else{
            // cout << "comparing " << i << " with "<< i+1<< " ..."<< endl;

            if(an[i-1] < an[i]&& i !=0){
                cout << "LOSS"<<endl;
                
                return 0;
                
            }
            else if (i == 4){
                cout << "WIN" <<endl;
                return 0;
            }
            prevCubeV = cubeV;
        }
   }
   



    

    

    return 0;

}
