#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void shift(vector<int>& numbers) {
    rotate(numbers.begin(), numbers.begin() + (numbers[0] % numbers.size()), numbers.end());
}
void shift(vector<int>& numbers, int a) {
    rotate(numbers.rbegin(), numbers.rbegin() + (a % numbers.size()), numbers.rend());
}
int main() {
    vector<int> numbers;
    int a = 0;
    cin >> a;
    cout<<endl;
    for(int i = 0; i < a; i++) {
        int n = 0;
        cin >> n;
        numbers.push_back(n);
    }
    cout << endl;
    if (( numbers[0] % 2)==0)
        shift(numbers);
    else
        shift(numbers,a-1);
    
    for (int i = 0; i< numbers.size(); i++)
        cout << numbers[i]<<endl;
    
    return 0;
}