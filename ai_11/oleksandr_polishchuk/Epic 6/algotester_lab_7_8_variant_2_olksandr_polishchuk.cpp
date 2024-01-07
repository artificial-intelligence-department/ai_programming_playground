#include <iostream>

using namespace std;

template <typename T>  
class Array
{
    public:

    T *container;
    int capacity = 1;
    int size =0;
    Array ()
    {   
        capacity = 1;
        container = new T[capacity];
        size = 0;
    }
    public:
    void insert(int index, int number, T arr[])
    {   
        
        if (size + number < capacity)
            {
                for (int i = size - 1; i > index - 1; i--)
                {
                    container[i + number] = container[i];
                }

                for (int j = 0; j < number; j++)
                {
                    container[index + j] = arr[j];
                }
                size += number;
            }
        
        else 
        {       
            while (size + number >= capacity)
            {
                capacity *= 2;
            }
            T *newCountainer = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newCountainer[i] = container[i];
            }
            for (int i = 0; i < number; i++)
            {
                newCountainer[index + i] = arr[i];
            }
            for (int i = index; i < size; i++)
            {
                newCountainer[i + number] = container[i];
            }
            container = newCountainer;
            size += number;
        }
    }
    void print()
    {
        for(int i = 0; i < size; i++)
        {
            cout << container[i] << " ";
        }
        cout << endl;   
    }

    void erase(int index, int n)
    {
        for(int i = index; i < size; i++)  
        {
            container[i] = container[i + n];
        }
        size -= n;
    }

    int getCapacity()
    {
        return capacity;
    }

    int getSize() const
    {
        return size;
    }

    T get(int index)
    {
        return container[index];
    }

    void set(int index, T newData)
    {
        container[index] = newData;
    }
};
int main()
{
    Array<int> initialArray;
    int q;
    cin >> q;
    for (int i = 0; i < q; i ++)
    {   
        string input;
        cin >> input;

        if (input == "size")
        {
            cout << initialArray.getSize() << endl;
        }
        else if (input == "capacity")
        {
            cout << initialArray.getCapacity() << endl;
        }
        else if (input == "insert")
        {
            int index, n;
            cin >> index >> n;
            int array[n];
            for (int i = 0; i < n; i++) 
            {  
                cin >> array[i];  
            } 
            initialArray.insert(index, n, array);
        }
        else if (input == "print")
        {
            initialArray.print();
        }
        else if (input == "set")
        {
            int index, data;
            cin >> index >> data;
            initialArray.set(index, data);
        }
        else if (input == "erase")
        {
            int index, n;
            cin >> index >> n;
            initialArray.erase(index, n);
        }
        else if (input == "get")
        {
            int index;
            cin >> index;
            cout << initialArray.get(index) << endl;
        }
    }
    return 0;
}

