#include <iostream>

using namespace std;

const int S = 3; 
void result(int m1[S][S], int m2[S][S], int sum[S][S], int trans[S][S]) {
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            sum[i][j] = m1[i][j] + m2[i][j];
        }
    }
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            trans[i][j] = sum[j][i];
        }
    }
}

int main() {
    int m1[S][S];
    int m2[S][S];
    for(int i=0; i<S; i++){
        for(int j=0; j<S; j++){
            cin>>m1[i][j];
        }
        cout<<endl;
    }
    for(int i=0; i<S; i++){
        for(int j=0; j<S; j++){
            cin>>m2[i][j];
        }
        cout<<endl;
    }
    int sum[S][S];
    int trans[S][S];
    result(m1, m2, sum, trans);
    cout<< "Сума:" <<endl;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << sum[i][j]<<" ";
        }
        cout<<endl;
    }
    cout << "Транспонована матриця:" << endl;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << trans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
