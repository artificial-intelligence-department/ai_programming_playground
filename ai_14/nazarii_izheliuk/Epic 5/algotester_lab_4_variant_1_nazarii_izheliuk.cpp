#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;

    cin >> N;
    int arN[N];
    for (int i = 0; i < N; i++) {
        cin >> arN[i];
    }

    cin >> M;
    int arM[M];
    for (int i = 0; i < M; i++) {
        cin >> arM[i];
    }

    sort(arN, arN + N);
    sort(arM, arM + M);
    // Знаходимо різницю між масивами
    int differenceN[N]; 

    auto itN = set_difference(arN, arN + N, arM, arM + M, differenceN);
    int diff_Count_N = itN - differenceN; 
    //різниця N-M
    cout << diff_Count_N << endl;
    for (int i = 0; i < diff_Count_N; ++i) {
        cout << differenceN[i] << " ";
    }
    cout << endl;

    //Знаходимо різницю між M-N
    int differenceM[M];

    auto itM = set_difference(arM, arM + M, arN, arN + N, differenceM);
    int diff_Count_M = itM - differenceM;
    cout << diff_Count_M << endl;
    for (int i = 0; i < diff_Count_M; i++){
        cout << differenceM[i] << " ";
    }
    cout << endl;

    //Перетин
    int intersection[N + M];

    auto it_intersection = set_intersection(arN, arN + N, arM, arM + M, intersection);
    int inter_Count = it_intersection - intersection;
    cout << inter_Count << endl;
    for (int i = 0; i < inter_Count; i++){
        cout << intersection[i] << " ";
    }
    cout << endl;

    //Обєднання
    int unionn[N + M];

    auto uni = set_union(arN, arN + N, arM, arM + M, unionn);
    int unionn_Count = uni - unionn; 

    cout << unionn_Count << endl;
    for (int i = 0; i < unionn_Count; ++i) {
        cout << unionn[i] << " ";
    }
    cout << endl;
    
    //Симетрична різниця
    int symmetric_diff[N + M];

    auto sym_diff = set_symmetric_difference(arN, arN + N, arM, arM + M, symmetric_diff);
    int sym_diff_Count = sym_diff - symmetric_diff; 

    cout << sym_diff_Count << endl;
    for (int i = 0; i < sym_diff_Count; ++i) {
        cout << symmetric_diff[i] << " ";
    }
    cout << endl;

}