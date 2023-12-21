#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int findMax(int n, int ar[]);
int findLongest(const string& str);

int main()
{
    int ar[] = {3, 9, 4, 2, 0, 7, 1, 5, 8, 6};
    int max_number = findMax(10, ar);
    cout << "The greatest number is: " << max_number << endl;

    string str = "A text for calculating the size of the longest word";
    int max_word_length = findLongest(str);
    cout << "The longest word's length is: " << max_word_length;

    return 0;
}

int findMax(int n, int ar[])
{
    return *max_element(ar, ar + n);
}

int findLongest(const std::string& str)
{
    int tmp = 0, max = 0;
    for (char ch : str)
    {
        if (isalpha(ch))
        {
            tmp++;
        }
        else
        {
            max = std::max(max, tmp);
            tmp = 0;
        }
    }
    return std::max(max, tmp);
}
