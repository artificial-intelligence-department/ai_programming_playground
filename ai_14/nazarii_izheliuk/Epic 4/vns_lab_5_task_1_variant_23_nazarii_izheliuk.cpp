#include<iostream>

using namespace std;



int main(){
    int N, i, last_element;

    cout << "Enter size of aray: " ;
    cin >> N;
    
    int aray1[N];
    int aray2[N][N];

    cout << "Enter elements of aray: " << endl;
    
    for(i = 0; i < N; i++){
        cin >> aray1[i] ; 
        if(aray1[i] < N){
            cout << "Element must be > N";
            exit(0);
        }
    }   

    for(i = 0; i < N ; i++){
        int fill = aray1[i];
        for(int j = 0; j < N ; j++){
            fill = fill / 2;
            aray2[j][i] = fill;
        }
    }
    
    for(i = 0; i < N; i++){
        aray2[N-1][i] = 0;
    }
    // for(i = 0; i < N; i++){
    //     cout << "[ " << aray2[N-1][i] << " ] ";
    // }
    cout << endl;
    for(i = 0; i < N; i++){
        last_element = aray1[i];
        for(int j = 0; j < N; j++){
            last_element = last_element - aray2[j][i];
        }
        aray2[N-1][i] = last_element;
        // cout << "[ " << last_element << " ]" << endl;
          
    }


    for(i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << " [ " << aray2[i][j] << " ] "; 
            
        }
        cout << endl;
    }

    
    return 0;
}