#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
class dynamicarray
{
private:
    vector<int> array;
    int capacity = 1;
public:
    void insert(int index, int N, vector<int> insertarray)
    {
        array.insert(array.begin() + index, insertarray.begin(), insertarray.end());
        if (array.size() >= capacity)
        {
            while (capacity <= array.size())
            {
                capacity = capacity * 2;
            }
            
        }
    }
    int get(int index)
    {
        return array[index];
    }
    int size()
    {
        return array.size();
    }
    void set(int index, int number)
    {
        array[index] = number;
    }
    void erase(int index, int amount)
    {
        array.erase(array.begin() + index, array.begin() + index + amount);
    }
    void print()
    {
        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
    }
    int capacity_()
    {
        return capacity;
    }

};

int main()
{
    dynamicarray test;
    string identificator;
    int Q;
    cin >> Q;
    cin.ignore(30000, '\n');
    for (int m = 0; m < Q; m++)
    {
        
        cin >> identificator;
        if (identificator == "insert")
        {
            int index;
            cin >> index;
            int N;
            cin >> N;
            cin.ignore(30000, '\n');
            int j;
          
            vector<int> input;
            for (int i = 0; i < N; i++)
            {
                cin >> j;
                input.push_back(j);
            }
            cin.ignore(30000, '\n');
            test.insert(index, N, input);
           
            cout << endl;
        }
        if (identificator == "get")
        {
            int index;
            cin >> index;
            cin.ignore(30000, '\n');
            cout << test.get(index);
            cout << endl;
        }
        if (identificator == "size")
        {
            cout << test.size();
            cout << endl;
            
        }
        if (identificator == "set")
        {
            int x;
            cin >> x;
            int y;
            cin >> y;
            test.set(x, y);
          
            cout << endl;
            
        }
        if (identificator == "erase")
        {
            int x;
            cin >> x;
            int y;
            cin >> y;
            test.erase(x, y);
           
            cout << endl;

        }
        if (identificator == "print")
        {
        
            test.print();
            cout << endl;

        }
        if (identificator == "capacity")
        {

            cout << test.capacity_();
            cout << endl;

        }
    }



}


