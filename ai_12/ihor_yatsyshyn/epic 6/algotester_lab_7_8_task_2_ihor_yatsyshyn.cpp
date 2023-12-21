#include <iostream>

using namespace std;

class DynamicArray 
{
private:
    int size;
    int capacity;
    int *arr;
   
public:
    DynamicArray() : arr(nullptr), size(0), capacity(1)
    {
        arr = new int[capacity];
    }

    ~DynamicArray() 
    {
        
    }

    void insert(int index, int num, int *data)
    {
        if (size + num >= capacity)
        {
            while (size + num >= capacity)
            {
                capacity *= 2;
            }

            int *newArr = new int[capacity];

            for (int i = 0; i < index; i++)
            {
                newArr[i] = arr[i];
            }

            for (int i = 0; i < num; i++)
            {
                newArr[index + i] = data[i];
            }

            for (int i = index; i < size; i++)
            {
                newArr[num + i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
        }
        else
        {
            for (int i = size - 1; i >= index; i--)
            {
                arr[i + num] = arr[i];
            }

            for (int i = 0; i < num; i++)
            {
                arr[index + i] = data[i];
            }
        }

        size = size + num;
    }

    void erase(int index, int num)
    {
        int left = size - index - num;

        for (int i = 0; i < left; ++i)
        {
            arr[index + i] = arr[index + i + num];
        }
            
        size -= num;
    }

    int get_size()
    {
        return size;
    }

    int get_capacity()
    {
        return capacity;
    }

    int& operator[](int index) 
    {
        return arr[index];
    }

    int get(int index)
    {
        return arr[index];
    }

    void set(int index, int data)
    {
        arr[index] = data;
    }

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {
    int Q;
    DynamicArray array;

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        string request;

        cin >> request;

        if (request == "insert")
        {
            int index, num;
            
            cin >> index >> num;

            int *data = new int[num];

            for (int i = 0; i < num; i++)
            {
                cin >> data[i];
            }
            
            array.insert(index, num, data);
            delete[] data;
        }
        else if (request == "erase")
        {
            int index, num;

            cin >> index >> num;
            array.erase(index, num);
        }
        else if (request == "size")
        {
            cout << array.get_size() << endl;
        }
        else if (request == "capacity")
        {
            cout << array.get_capacity() << endl;
        }
        else if (request == "get")
        {
            int index;

            cin >> index;
            cout << array.get(index) << endl;
        }
        else if (request == "set")
        {
            int index, data;

            cin >> index >> data;
            array.set(index, data);
        }
        else if (request == "print")
        {
            array.print();
        }     
    }

    return 0;
}