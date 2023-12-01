#include<iostream>
using namespace std;

void bubbleSort(int road[], int length) 
{ 
    int i, j; 
    for (i = 0; i < length - 1; i++)  
        for (j = 0; j < length - i - 1; j++) 
            if (road[j] > road[j + 1]) 
                swap(road[j], road[j + 1]); 
} 
int main(){
    int  length, i;
     cin>> length;    
 if(length<1||length>100000){
     return 0;
    }

    int road[length];
 for(i=0; i<length; i++){
        cin>> road[i];
        if(road[i]<0 || road[i]>100000){
            return 0;
            }
    }

 if(length == 1){
    cout<< 0;
    return 0;
    }
 bubbleSort(road, length);
int  a = road[length-2]-road[0]; 
int  b = road[length-1]-road[1];
int result = min(a,b);
cout<< result ;
}
