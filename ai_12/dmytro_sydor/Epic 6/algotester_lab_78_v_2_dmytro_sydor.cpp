#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class DynamicArray
{
private:
    long int *array;
    long int size;
    long int capacity;

    void resize(long int newCapacity)
    {
        long int *tempArray = new long int[newCapacity];
        std::copy(array, array + size, tempArray);
        delete[] array;
        array = tempArray;
        capacity = newCapacity;
    }

public:
    DynamicArray()
    {
        array = nullptr;
        size = 0;
        capacity = 1;
        array = new long int[capacity];
    }
    // деструктор
    ~DynamicArray()
    {
        delete[] array;
    }

    void insert(long int A, long int N, long int *value)
    {
        if (A < 0 || A > size)
            return;

        if (size + N >= capacity)
        {
            long int changedCapacity = capacity;

            while (size + N >= changedCapacity)
            {
                changedCapacity *= 2;
            }
            long int *changedArr = new long int[changedCapacity];
            size += N;

            for (int i = 0; i < size; ++i)
            {
                changedArr[i] = array[i];
            }

            delete[] array;
            array = changedArr;

            std::copy_backward(array + A, array + size - N, array + size);
            for (long int i = 0; i < N; ++i)
            {
                array[A + i] = value[i];
            }

            capacity = changedCapacity;
        }
        else
        {

            for (long int i = size - 1; i >= A; --i)
            {
                array[i + N] = array[i];
            }

            for (long int i = 0; i < N; ++i)
            {
                array[A + i] = value[i];
            }

            size += N;
        }
    }

    void erase(long int A, long int n)
    {
        long int deleteCount = std::min(n, size - A);
        for (long int i = A; i < size - deleteCount; ++i)
        {
            array[i] = array[i + deleteCount];
        }

        size -= deleteCount;
    }

    long int Size() const
    {
        return size;
    }

    long int Capacity() const
    {
        return capacity;
    }

    void print() const
    {
        for (long int i = 0; i < size; ++i)
        {
            std::cout << array[i] << " ";
        }
    }

    long int &operator[](long int A)
    {
        return array[A];
    }
};

int main()
{

    long int Q;
    cin >> Q;

    DynamicArray dynamicArray;

    while (Q--)
    {
        string query;
        cin >> query;

        if (query == "insert")
        {
            long int A, N; // A - позиція, N - кількість елементів
            cin >> A >> N;
            long int *elements = new long int[N];
            for (long int i = 0; i < N; ++i)
            {
                cin >> elements[i];
            }
            dynamicArray.insert(A, N, elements);
            delete[] elements;
        }
        else if (query == "erase")
        {
            long int A, n;
            cin >> A >> n;
            dynamicArray.erase(A, n);
        }
        else if (query == "size")
        {
            cout << dynamicArray.Size() << endl;
        }
        else if (query == "capacity")
        {
            cout << dynamicArray.Capacity() << endl;
        }
        else if (query == "get")
        {
            long int A;
            cin >> A;
            if (A >= 0 && A < dynamicArray.Size())
            {
                cout << dynamicArray[A] << endl;
            }
        }
        else if (query == "set")
        {
            long int A, value;
            cin >> A >> value;
            if (A >= 0 && A < dynamicArray.Size())
            {
                dynamicArray[A] = value;
            }
        }
        else if (query == "print")
        {
            dynamicArray.print();
            cout << endl;
        }
    }

    return 0;
}
