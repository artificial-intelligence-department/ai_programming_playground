#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long n;
    long long a, b, c;
    long long value;
    vector<long long> myarray = {};
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        myarray.push_back(value);
    }
    cin >> a >> b >> c;

    for (int i = 0; i < myarray.size(); i++)
    {
        if (myarray[i] == a || myarray[i] == b || myarray[i] == c)
        {
            myarray.erase(myarray.begin() + i);
            i--;
        }
    }
    vector<long long> new_myarray2 = {};
    if (myarray.empty()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < myarray.size() - 1; i++)
    {
        new_myarray2.push_back(myarray[i] + myarray[i + 1]);
    }
    cout << new_myarray2.size() << endl;
    for (int i = 0; i < new_myarray2.size(); i++)
    {
        cout << new_myarray2[i] << " ";
    }
}
