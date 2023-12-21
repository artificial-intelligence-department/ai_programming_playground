#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(){    

    string numbers;

    getline(cin , numbers);

    sort(numbers.rbegin() , numbers.rend());

    cout << numbers;

    return 0;
}