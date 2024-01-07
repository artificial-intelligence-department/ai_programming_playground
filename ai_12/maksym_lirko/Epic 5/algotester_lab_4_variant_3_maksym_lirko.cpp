#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void removeFUNC(vector<int> &array) 
{   
    for (auto i = array.begin(); i < array.end(); i++)
    {
        int element = *i;
        for (auto j = i + 1; j < array.end();)
        {
            if (element == *j)
            {
                j = array.erase(j);
            }
            else
            {
                j++;
            }
        }
    }
}

void sort(vector<int> &array) 
{
    int size = array.size();
     for (int i = 0; i < size; i++)
    {
        int i2 = i;

        for (int j = i+1; j < size; j++)
        {
            if(array[j]<array[i2])
            i2 = j; 
        }
        swap(array[i],array[i2]); 
    }
}

void SwapFUNC(vector<int> &array) 
{
     int size = array.size() - 1;
    for (int i = 0; i < size; i++)
    {
        int temp = array[i];
        array[i] = array[size];
        array[size] = temp;
        size--;
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> array(N);

    for (int i = 0; i < N; i++) 
    {
        cin >> array[i];
    }

    vector<int> remain1, remain2, remain3;

    for (int i = 0; i < N; i++) 
    {
        if (array[i] % 3 == 0) 
        {
            remain1.push_back(array[i]);
        } 
        else if (array[i] % 3 == 1) 
        {
            remain2.push_back(array[i]);
        } 
        else 
        {
            remain3.push_back(array[i]);
        }
    }

    sort(remain1) , sort(remain2) , sort(remain3);

    removeFUNC(remain1) , removeFUNC(remain2) , removeFUNC(remain3);

    SwapFUNC(remain2);

    int suma = remain1.size() + remain2.size() + remain3.size();
    cout << suma << endl;

    for(int i = 0; i < remain1.size(); i++) 
    {
    cout << remain1[i] << "\t";
    }

    for(int i = 0; i < remain2.size(); i++) 
    {
    cout << remain2[i] << "\t";
    }

    for(int i = 0; i < remain3.size(); i++) 
    {
    cout << remain3[i] << "\t";
    }

 return 0;
}
