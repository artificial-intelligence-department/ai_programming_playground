#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
private:
    T* data;       
    int size;    
    int capacity; 
       
    void reserve(int newCapacity)
    {
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) 
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:

    DynamicArray()
    {
        data = nullptr;
        size = 0;
        capacity = 1;
    }

    ~DynamicArray() 
    {
        delete[] data;
    }

    void insert(int index, int N, T* array) 
    {
        if (index > size) 
        {
            return;
        }

        if (size + N >= capacity) 
        {
            while(size + N >= capacity)
            {
                capacity *= 2;
                reserve(capacity);
            }
        }


        for (int i = size; i > index; --i) 
        {
            data[i + N - 1] = data[i - 1];
        }

        for (int i = 0; i < N; ++i) 
        {
            data[index + i] = array[i];
        }
        size += N;
    }

    void erase(int index, int n) 
    {
        if (index >= size) 
        {
            return;
        }


        int eraseCount = min(n, size - index);

     
        for (int i = index; i < size - eraseCount; ++i) 
        {
            data[i] = data[i + eraseCount];
        }

        size -= eraseCount;
    }

 
    int getSize() const 
    {
        return size;
    }


    int getCapacity() const 
    {
        return capacity;
    }

  
    T& operator[](int index) 
    {
        return data[index];
    }


    const T& operator[](int index) const 
    {
        return data[index];
    }

  
    void print() const 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << data[i] << ' ';
        }
        cout << endl;
    }
};

int main() 
{
    int Q;
    cin >> Q;

    DynamicArray<int> dynamicArray;

    while (Q--) 
    {
        string query;
        cin >> query;

        if (query == "insert") 
        {
            int index, N;
            cin >> index >> N;

            int* array = new int[N];
            for (int i = 0; i < N; ++i) 
            {
                cin >> array[i];
            }

            dynamicArray.insert(index, N, array);
            delete[] array;
        } 
        else if (query == "erase") 
        {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        } 
        else if (query == "size") 
        {
            cout << dynamicArray.getSize() << endl;
        } 
        else if (query == "capacity") 
        {
            cout << dynamicArray.getCapacity() << endl;
        } 
        else if (query == "get") 
        {
            int index;
            cin >> index;
            cout << dynamicArray[index] << endl;
        } 
        else if (query == "set") 
        {
            int index, value;
            cin >> index >> value;
            dynamicArray[index] = value;
        } 
        else if (query == "print") 
        {
            dynamicArray.print();
        }
    }
}
