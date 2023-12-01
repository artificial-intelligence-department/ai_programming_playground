#include <iostream>
#include <vector>
#include <string>
using namespace std;

int func(const vector<int> &a) {
    int sum = 0;
    
    for (int number : a) {
        sum += number;
    }

    return (sum / a.size());
}

int func(const string &a) {
    int count = 0;
    
    for (auto letter : a) {
        if (isalpha(letter)) count++;
    }

    return count;
}

int main(){

    vector<int> test1 = {2, 4, 10, 13, 56, 17};
    string test2 = "Hello world";
    vector<int> test3 = {13, 55, 11, 38, 56, 1, 32, 22};
    string test4 = "I love C++";
    
    cout << func(test1) << endl;
    cout << func(test2) << endl;
    cout << func(test3) << endl;
    cout << func(test4) << endl;

    return 0;
}