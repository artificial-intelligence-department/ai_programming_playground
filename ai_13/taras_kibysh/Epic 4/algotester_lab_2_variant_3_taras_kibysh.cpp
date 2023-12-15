#include <cstdio>
#include <iostream>
int main(){

     using namespace std;

   
    long int N;

    scanf("%i", &N);
     long int drone1 = 0, drone2 = N-1;

     int field[N];


    for(int i = 0;i<N; i++)
    cin>>field[i];


    
    long int place1 = 0;
     long int place2 = N-1;

drone1 = 0;
drone2 = N-1;

while(true){
   
    //  if(drone1>=N || drone2 < 0){
    //     return 0;
    // }


    if(drone1 == drone2 ){
    cout << drone1 + 1 << " ";
    cout << drone2 + 1 << "\n";
    cout << "Collision";
    
    return 0;
    }

    if(drone1>drone2){


        cout << drone1 + 1 <<" ";
        cout << drone2 + 1 << "\n";
        cout << "Miss";

        return 0;
    }

    if(drone2 == drone1+1){
      

       cout << drone1 + 1 << " ";
       cout << drone2 + 1 << "\n";
       cout<< "Stopped";

        return 0;
    }

     place1 = place1 + field[drone1];
    drone1 = place1;

    //розрахунки 2 дрона
    place2 = place2 - field[drone2];
    drone2 = place2;




}
return 0;


}