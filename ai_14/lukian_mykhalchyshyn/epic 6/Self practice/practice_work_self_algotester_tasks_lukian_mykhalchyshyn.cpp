#include <iostream>
#include <vector>

using namespace std;

int sequence(vector <int> & num) //довжина найбільшої зростаючої підпослідовності
{
    int n = num.size();

    if (n == 0) // Якщо вхідна послідовність порожня, найбільша зростаюча підпослідовність також порожня
    {
        return 0;
    }

    vector <int> arr(n, 1); // зберігання довжини найбільшої зростаючої підпослідовності

    for (int i = 1; i < n; ++i) 
    {
        for (int j = 0; j < i; ++j) 
        {
            if (num[i] > num[j]) 
            {
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
    }

    int max = 0;

    for (int i = 0; i < n; ++i) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

int main() 
{
    int n;

    cin >> n; // Зчитування розміру послідовності

    vector <int> num(n);

    for (int i = 0; i < n; ++i) // Зчитування елементів послідовності
    {
        cin >> num[i];
    }

    int result = sequence(num);

    cout << result << endl;

    return 0;
}
