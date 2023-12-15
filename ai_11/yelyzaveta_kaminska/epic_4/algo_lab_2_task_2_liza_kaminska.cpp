#include <iostream>
#include <vector>
using namespace std;

int main() {
    long size;
    long num_1, num_2, num_3;
    long element;
    vector<long> numbers = {};

    cin >> size;

    for (int i = 0; i < size; ++i) {
        cin >> element;
        numbers.push_back(element);
    }

    cin >> num_1 >> num_2 >> num_3;

    for (int i = 0; i < numbers.size();) {
        if (numbers[i] == num_1 || numbers[i] == num_2 || numbers[i] == num_3) {
            numbers.erase(numbers.begin() + i);
        } else {
            ++i;
        }
    }

    vector<long long> sum_array = {};
    if (numbers.empty()) {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < numbers.size() - 1; ++i) {
        sum_array.push_back(numbers[i] + numbers[i + 1]);
    }

    cout << sum_array.size() << endl;
    for (int i = 0; i < sum_array.size(); ++i) {
        cout << sum_array[i] << " ";
    }

    return 0;
}
