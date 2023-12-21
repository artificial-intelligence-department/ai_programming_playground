#include <iostream>
using namespace std;

int main() {
    int lengthN, lengthM, count=0;

    cin>>lengthN;
    int *N=new int[lengthN];
    for(int i=0; i<lengthN; i++){
        cin>>N[i];
    }

    cin>>lengthM;
    int *M=new int[lengthM];
    for(int i=0; i<lengthM; i++){
        cin>>M[i];
    }

    for(int i=0; i<lengthM; i++){
        for(int j=0; j<lengthN; j++){
            if(M[i]==N[j]){
                count++;
            }
        }
    }
    cout<<count<<endl;
    cout<<(lengthN+lengthM-count);

}


