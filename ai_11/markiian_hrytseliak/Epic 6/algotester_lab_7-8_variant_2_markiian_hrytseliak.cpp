#include <iostream>

using  namespace std;

template <typename T>

class DynamicArray 
{
private:
    T* arr;       
    int size;      
    int capacity;  

public:
    
    DynamicArray() 
    {
        arr = nullptr;
        size = 0;
        capacity = 1;
    }
    
    ~DynamicArray() 
    {
        delete[] arr;
    }

    
    void insert(int index, int N, const T* values) 
    {
    if (index < 0 || index > size) {
        cerr << "Invalid index for insert!" << endl;
        return;
    }

    if (size + N >= capacity) 
    {
        
        while(size + N >= capacity)
        {
            capacity *= 2;
            resize(capacity);
        }
    }

    
    for (int i = size - 1; i >= index; --i) 
    {
        arr[i + N] = arr[i];
    }

    
    for (int i = 0; i < N; ++i) {
        arr[index + i] = values[i];
    }

    size += N;

    }
    
    void erase(int index, int n) 
    {
        if (index < 0 || index >= size || n < 0) 
        {
            cerr << "Invalid index or count for erase!" << endl;
            return;
        }

        
        for (int i = index + n; i < size; ++i) 
        {
            arr[i - n] = arr[i];
        }

        size -= n;
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
        if (index < 0 || index >= size) 
        {
            cerr << "Index out of bounds!" << endl;
            exit(1);
        }

        return arr[index];
    }

    
    void set(int index, T value) 
    {
        if (index < 0 || index >= size) 
        {
            cerr << "Index out of bounds!" << endl;
            return;
        }

        arr[index] = value;
    }

    
    void print() const 
    {
        for (int i = 0; i < size; ++i) 
        {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

private:
    
    void resize(int newCapacity) 
    {
        T* newArr = new T[newCapacity];
        for (int i = 0; i < size; ++i) 
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }
};

int main() 
{
    int Q;
    cin >> Q;

    DynamicArray<int> dynamicArray;

    while (Q--) 
    {
        string operation;
        cin >> operation;
        
        if (operation == "insert") 
        {
            int index, N;
            cin >> index >> N;

            int* values = new int[N];
            for (int i = 0; i < N; ++i) 
            {
                cin >> values[i];
            }

            dynamicArray.insert(index, N, values);
            delete[] values;
        } 
        else if (operation == "erase") 
        {
            int index, n;
            cin >> index >> n;
            dynamicArray.erase(index, n);
        } 
        else if (operation == "size") 
        {
            cout << dynamicArray.getSize() << endl;
        } 
        else if (operation == "capacity") 
        {
            cout << dynamicArray.getCapacity() << endl;
        } 
        else if (operation == "get") 
        {
            int index;
            cin >> index;
            cout << dynamicArray[index] << endl;
        } 
        else if (operation == "set") 
        {
            int index, value;
            cin >> index >> value;
            dynamicArray.set(index, value);
        } 
        else if (operation == "print") 
        {
            dynamicArray.print();
        }
    }
    return 0;
}