#include <iostream>
#include <string>

using namespace std;

int count(int *arr, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 1)
        {
            count++;
        }
    }
    return count;
}

int count(const string &str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    if (str[str.length() - 1] != ' ')
    {
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }    
    cout << "Кількість непарних елементів у масиві: " << count(arr, n) << endl;

    string str;
    cin.ignore(INT_MAX, '\n');
    getline(cin, str);
    cout << "Кількість слів у рядку: " << count(str) << endl;

    delete[] arr;
    return 0;
}