#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {
    int N;
    cin >> N;


    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }


    vector<int> correct;
    int countDivisibleBy3 = 0;


    for (int i = 0; i < N; ++i) {
        correct.push_back(numbers[i]);


        if (numbers[i] % 3 == 0) {
            countDivisibleBy3++;
        }
    }


    sort(correct.begin(), correct.end(), [countDivisibleBy3](int a, int b) {
        if (a % 3 == 1 && b % 3 == 1) {
            return a > b;
        }
        return make_pair(a % 3, a) < make_pair(b % 3, b);
    });


    correct.erase(unique(correct.begin(), correct.end()), correct.end());


    cout << correct.size() << endl;
    for (int num : correct) {
        cout << num << " ";
    }


    return 0;
}
