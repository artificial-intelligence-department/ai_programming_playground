#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{   
    int result=0;
    for(int i=20; i<=100; i++){
        if(i % 3==0){
           result+=i;
       }
    }
    cout<<result;
}