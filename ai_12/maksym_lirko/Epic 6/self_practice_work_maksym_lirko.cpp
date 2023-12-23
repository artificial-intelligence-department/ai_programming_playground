#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, A, B, C;

    cin >> N;

    vector<int> array(N);

    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
    }

    cin >> A >> B >> C;

    for (auto i = array.begin(); i < array.end();)
    {
        if (*i == A)
        {
            i = array.erase(i);
        }
        else if (*i == B)
        {
            i = array.erase(i);
        }
        else if (*i == C)
        {
            i = array.erase(i);
        }
        else
        {
            i++;
        }
    }

    if (array.size() <= 1) 
    {
        cout << "0" << endl;
        return 0;
    }

    int counter = 0;
    vector<int> array2;

    for (int i = 0; i<array.size()-1; i++)
    {
        int suma = array[i] + array[i+1];
        array2.push_back(suma);
        counter++;
    }

    cout<<counter<<endl;

    for (int i = 0; i<array2.size(); i++)
    {
        cout<<array2[i]<<"  ";
    }
    return 0;
}
