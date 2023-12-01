#include <iostream>
using namespace std;

const int lines = 5;
const int raws = 5;

void swappingrow(int masa[][raws], int index1, int index2){
    for(int i = 0; i < raws; i++){
        int temp = masa[index1][i];
        masa[index1][i]=masa[index2][i];
        masa[index2][i]=temp;
    }

    return;
}
void swappingcolumns(int masa[][raws], int index1, int index2){
    for(int i = 0; i < lines; i++){
        int temp = masa[i][index1];
        masa[i][index1]=masa[i][index2];
        masa[i][index2]=temp;
    }

    return;
}


int main(){
int masa[lines][raws];

for(int i = 0; i < lines; i++){
        for(int j = 0; j < raws; j++){
            cin >> masa[i][j];
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i < lines; i++){
        for(int j = 0; j < lines; j++){
            if(masa[i][0] == masa[j][0]){
                swappingrow(masa, i, j);
            }
        }
    }
    // Print an array.
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < raws; j++){
            cout << masa[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < raws; i++){
        for(int j = 0; j < raws; j++){
            if(masa[0][i] == masa[0][j]){
                swappingcolumns(masa, i, j);
            }
        }
    }
// Print an array.
    for(int i = 0; i < lines; i++){
        for(int j = 0; j < raws; j++){
            cout << masa[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}
