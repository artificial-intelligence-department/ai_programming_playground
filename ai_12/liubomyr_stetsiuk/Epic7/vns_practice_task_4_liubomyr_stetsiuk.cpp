#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    long double average;
    long double sum;
    cout << "Ведіть кількість дробових чисел > ";
    cin >> n;
    vector<long double> numbers(n);
    for (int i = 0; i < numbers.size(); i++)
    {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    cout << "Найбільший елемент масиву > " << numbers[numbers.size() - 1] << endl;
    cout << "Найменший елемент масиву > " << numbers[0] << endl;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    average = sum * 0.5;
    cout << "Середнє значення масиву > " << average;
    return 0;
}
