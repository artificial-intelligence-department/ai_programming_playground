#include <iostream>
using namespace std;
int main(){
    int N, first=0; 
    cin>>N;
    int second = N-1;
    int* array=new int[N];
    for ( int i=0; i<N; i++){
        cin>>array[i];
    }
    while(true){
        if(first == (second - 1)){
            cout<<++first<<" "<<++second<<endl;
            cout<<"Stopped";
            break;
        } 
        if( first == second){
            cout<<++first<<" "<<++second<<endl;
            cout<<"Collision";
            break;
        }
        if(first>second){
            cout<<++first<<" "<<++second<<endl;
            cout<<"Miss";
            break;
        }
        first += array[first];
        second -= array[second];
    }
    delete[] array;
    return 0;
}
