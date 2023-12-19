#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main() {
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
    vector<int> differenceNM;
    set_difference(array1.begin(), array1.end(), array2.begin(), array2.end(), back_inserter(differenceNM));
    // Різниця масивів M-N
    vector<int> differenceMN;
    set_difference(array2.begin(), array2.end(), array1.begin(), array1.end(), back_inserter(differenceMN));
    // Вивести різницю масивів N-M
    cout << differenceNM.size() << endl;
    for (int num : differenceNM){
        cout << num << " ";
    }
    cout << endl;
    // Вивести різницю масивів M-N
    cout << differenceMN.size() << endl;
    for (int num : differenceMN){
        cout << num << " ";
    }
    cout << endl;
    // Перетин
    set<int> intersectionSet;
    for (int num : array1){
        if (find(array2.begin(), array2.end(), num) != array2.end()){
            intersectionSet.insert(num);
        }
    }
    //cout << "Перетин: ";
    cout << intersectionSet.size() << endl;
    for (int num : intersectionSet){
        cout << num << " ";
    }
    cout << endl;
    // Об'єднання
    set<int> unionSet(array1.begin(), array1.end());
    unionSet.insert(array2.begin(), array2.end());
    //cout << "Об'єднання: ";
    cout << unionSet.size() << endl;
    for (int num : unionSet){
        cout << num << " ";
    }
    cout << endl;
    // Симетрична різниця
    vector<int> symmetricDifference;
    for (int num : array1){
        if (find(array2.begin(), array2.end(), num) == array2.end()){
            symmetricDifference.push_back(num);
        }
    }
    for (int num : array2) {
        if (find(array1.begin(), array1.end(), num) == array1.end()){
            symmetricDifference.push_back(num);
        }
    }
    //cout << "Симетрична різниця: ";
    cout << symmetricDifference.size() << endl;
    for (int num : symmetricDifference){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
