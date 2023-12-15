#include <iostream>
using namespace std;

int greatest(int n, int ar[]);
int greatest(string str);

int main()
{
    int ar[] = {3, 9, 4, 2, 0, 7, 1, 5, 8, 6};
    int max_num = greatest(10, ar);
    cout << "The greatest number is: " << max_num << endl;

    string str = "A text for calculating the size of the longest word";
    int max_word = greatest(str);
    cout << "The longest word`s length is: "<< max_word;

    return 0;
}

int greatest(int n, int ar[])
{
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i] > max) max = ar[i]; 
    }
    return max;
}

int greatest(string str)
{
    int n = str.length(), tmp = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        if ((str[i] >= 'A' && str[i <= 'Z']) || (str[i] >= 'a' && str[i <= 'z'])) tmp++;
        else tmp = 0;
        if (tmp > max) max = tmp;
    }
    return max;
}