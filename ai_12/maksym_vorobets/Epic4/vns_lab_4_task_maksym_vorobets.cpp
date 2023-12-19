#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(nullptr));
    int M[5];
    cout<<"Масив:"<<endl;
    for(int i=0; i<5; i++){
    M[i]=rand()%100;
     cout<<M[i]<<endl;
    }
      for (int i = 0; i < 5; i++){
        if(M[i]==0){
            M[i]=rand()%100;
        }
      }
 
    for (int i = 0; i < 5; i++)
    {
        if (M[i] % 2 == 0) {
            M[i+1] = M[i - 1]+2;
            break;}
            
    }
    cout<<"Новий масив:"<<endl;
    for (int i = 0; i < 5; i++){
        cout << M[i]<<endl;
    }
    return 0;

        }

