#include<iostream>
using namespace std;
void wordmaker(int a[3][20]){
    int i,j;
     for(j = 0; j<3; j++){
        cout<<"(";
        for(i = 0; i<20; i++){
            if(a[j][i] != 0 ){
                cout<<a[j][i];
            } else{
            cout<<",";
              }
        }
        cout<<") ";
    }
}
int main(){
int a[3][20] = { 
{3, 4, 4, 6, 4, 0, 5, 2, 0, 9, 9, 5, 6, 5, 9, 6, 4, 1, 0, 4},
{5, 1, 5, 6, 0, 5, 8, 9, 9, 0, 1, 6, 3, 4, 9, 9, 7, 0, 2, 1},
{5, 7, 0, 1, 9, 5, 3, 8, 1, 4, 6, 0, 4, 7, 4, 8, 2, 6, 9, 8}
};

    wordmaker(a);

    return 0;
}