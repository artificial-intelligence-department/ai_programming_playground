#include <iostream>
using namespace std;
int sumOfelements(int n){ // 16. в коді використано параметри та аргументи функції
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int number, sum;
    cout << "enter the number of elements: ";
    cin >> number;
    sum = sumOfelements(number);
    cout << "sum of " << number << " first elements is " << sum;
    return 0;
}