#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void print_vector(const vector<int>& v){
    for (int i : v) {
        cout << i << ' ';
    }
    cout << '\n';
}
int main(){
    int N, M;
    // Зчитуємо розмір і елементи першого масиву
    cin >> N;
    if (N < 1 || N > 100){
        return 1;
    }
    vector<int> array1(N);
    for (int i = 0; i < N; ++i){
        cin >> array1[i];
    }
    // Зчитуємо розмір і елементи другого масиву
    cin >> M;
    if (M < 1 || M > 100){
        return 1;
    }
    vector<int> array2(M);
    for (int i = 0; i < M; ++i){
        cin >> array2[i];
    }
    cout << endl;
    // Різниця масивів N-M
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    vector<int> diff_N_M;
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(diff_N_M));

    vector<int> diff_M_N;
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(diff_M_N));

    vector<int> intersection;
    set_intersection(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(intersection));

    vector<int> union_set;
    set_union(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(union_set));

    vector<int> symm_diff;
    set_symmetric_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(symm_diff));
    // Print the results
    cout << diff_N_M.size() << endl;
    print_vector(diff_N_M);
    cout << diff_M_N.size() << endl;
    print_vector(diff_M_N);

    cout << intersection.size() << endl;
    print_vector(intersection);

    cout << union_set.size() << endl;
    print_vector(union_set);

    cout << symm_diff.size() << endl;
    print_vector(symm_diff);

    return 0;
}
