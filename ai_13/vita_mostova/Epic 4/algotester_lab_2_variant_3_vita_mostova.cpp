#include <iostream>
using namespace std;
int main(){
    int N ;
    cin>>N;
    int speed1=0;
    int speed2=N-1;
    const int SIZE_ARRAY = N; 
    int arr1[SIZE_ARRAY];
    for (int i=0;i<N;i++){
          cin>>arr1[i];
}

while ((speed1<=N-1)&&(speed2>=0)){
if(speed1==speed2){
    cout<<speed1+1<<" "<<speed2+1<<endl;
    cout<<"Collision";
    break;
}else if(speed1>speed2){
    cout<<speed1+1<<" "<<speed2+1<<endl;
    cout<<"Miss";
    break;
}else if(speed1==speed2-1){
    cout<<speed1+1<<" "<<speed2+1<<endl;
    cout<<"Stopped";
    break;
}
speed1+=arr1[speed1];
speed2-=arr1[speed2];
} 

    return 0;
    }






