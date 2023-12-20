#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void ccout(vector <int> &a){
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;
}


int main(){
    int N, M;
    cin >> N;
    vector <int> arr1(N);
    for (int i = 0; i < N; i++){
        cin >> arr1[i];
    }

    cin >> M;
    vector <int> arr2(M);
    for (int i = 0; i < M; i++){
        cin >> arr2[i];
    }
    cout << endl;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    //різниця N-M
    vector <int> a;
    set_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(a));
    ccout(a);

    //різниця M-N
    a.clear();
    set_difference(arr2.begin(), arr2.end(), arr1.begin(), arr1.end(), back_inserter(a));
    ccout(a);

    //їх перетин
    a.clear();
    set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(a));
    ccout(a);

    //їх об'єднання
    a.clear();
    set_union(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(a));
    ccout(a);

    //їх симетричну різницю
    a.clear();
    set_symmetric_difference(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(a));
    ccout(a);

    return 0;
}