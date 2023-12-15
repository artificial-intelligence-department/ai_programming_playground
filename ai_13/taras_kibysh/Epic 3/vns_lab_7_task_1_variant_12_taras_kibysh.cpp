#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> transfer(const std::vector<int> &values) {
    int sum = 0;
    int n = values.size() - 1;

    for (int value : values) {
        sum += value * pow(10, n);
        n--;
    }

    std::vector<int> result;
    int i = 0;

    while (sum > 0) {
        result.push_back(sum % 8);
        sum /= 8;
        i++;
    }

    return result;
}

int main() {
    using namespace std;    
    vector<int> values = {9, 2, 5};
    vector<int> result = transfer(values);
    
    vector<int> values2 = {1,7,3,6,1};
    vector<int> result2 = transfer(values2);
    
    vector<int> values3 = {5,6,1,4,3,5,1,4};
    vector<int> result3 = transfer(values3);

    cout << "Result №1 is:";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;

    cout << "Result №2 is:";
    for (int i = result2.size() - 1; i >= 0; i--) {
        cout << result2[i];
    }
    cout << endl;


    cout << "Result №3 is:";
    for (int i = result3.size() - 1; i >= 0; i--) {
        cout << result3[i];
    }
    cout << endl;


    return 0;
}
