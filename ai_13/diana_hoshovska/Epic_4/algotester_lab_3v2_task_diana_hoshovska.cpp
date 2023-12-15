#include <iostream>
using namespace std;

int main(){
    int N, M, counter1 = 0, counter2 = 0;

    cin >> N; //розміри масивів
    int arr1[N]={0};
    for (int i = 0; i < N; i++){
        cin >> arr1[i];
    }

    cin >> M;
    int arr2[M]={0};
    for (int i = 0; i < M; i++){
        cin >> arr2[i];
    }

    //sameElements
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (arr1[i]==arr2[j]){
                counter1++;
            }
        }
    }

    //uniqueElements
    counter2=N+M-counter1;
    cout << counter1 << endl;
    cout << counter2 << endl;

    return 0;
}
