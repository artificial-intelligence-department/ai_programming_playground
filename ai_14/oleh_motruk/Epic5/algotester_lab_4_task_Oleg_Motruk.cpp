#include <iostream>
#include <vector>

using namespace std;


void deleteandrotate(vector<int> &numbers , int k){
    int n = numbers.size();

    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < numbers.size() - 1; i++){
        if (numbers[i] == numbers[i+1]){
            numbers.erase(numbers.begin() + i);
            i--;
        }
    }

    for(int i = 0; i < k; i++){
        numbers.push_back(numbers[i]);
        numbers.erase(numbers.begin() + 0);
        i--;
        k--;
    }

    cout << numbers.size() << endl;

    for(int i = 0; i < numbers.size(); i++){
        cout << numbers[i] << " ";
    }
}

int main(){
    int n , k;

    cin >> n >> k;
    vector<int> numbers(n);

    deleteandrotate(numbers , k);

    return 0;
}