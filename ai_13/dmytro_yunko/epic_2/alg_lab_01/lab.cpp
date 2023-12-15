#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    
  
   int an[5] {0};

   for (size_t i = 0; i < 5; i++)
   {
    cout << "enter the length of the "<<i+1<<"  cube:"<<endl;
    cin>> an[i];
   }
   



    

    int prevCubeV {0};
    for (size_t i = 0; i < (sizeof(an)/sizeof(*an)); i++)
    {
    
        int cubeV = pow(an[i],3);
        // cout << i+1 << " cube:" << cubeV<< endl;

        if (i == 0) {
        
            prevCubeV = cubeV;
        }
        else if(an[i] <= 0){
            cout << "ERROR"<< endl;
            break; 
        }
        else{
            // cout << "comparing " << i << " with "<< i+1<< " ..."<< endl;
            
            if(prevCubeV < cubeV){
                cout << "LOSS"<<endl;
                break;
                
            }
            else if (i == (sizeof(an)/sizeof(*an)) - 1){
                cout << "WIN" <<endl;
            }
            prevCubeV = cubeV;
        }
  

    }
    


    return 0;
}
