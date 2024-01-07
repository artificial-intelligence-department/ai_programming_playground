#include <iostream>
#include <string>

using namespace std;

// <int>
template <typename T> //створюємо клас для будь якого типу данних
class DynamicArray
{
private:
    T* arr;
    int size;
    int capacity;
    const int growthFactor = 2;

    void resize()
    {
        do {
            capacity *= growthFactor; //збільшуємо фактичний розмір масиву
        } while (capacity <= size);

        T* newArr = new T[capacity]; //new виділяє пам'ять та повертає адресу цієї памяті
        for (int i = 0; i < size; i++)
            newArr[i] = arr[i];
        
        delete[] arr; //arr більше не посиляється на старі данні
        arr = newArr; //переписавши їй у новий збільшений масив в циклі for, ми перепосилаємо старий масив на новий
    }

public:
    DynamicArray() : size(0), capacity(1) {
        arr = new T[capacity];
    }
    ~DynamicArray() { //для автоматичного видалення данних, якщо їх життевий цикл закінчився (використання, напр у функціях)
        delete[] arr;
    }

    void insert(int index, int length, T* values)
    {
        if(index > size)
            return;
        
            //збільшуємо фактичний розмір масиву
        while (size + length >= capacity)
            resize();

            //тут ми копіюємо данні зі старого в новий, то того індексу, після якого нам треба вставити потрібно значення
        T* newArr = new T[capacity];
        for (int i = 0; i < index; i++) {
            newArr[i] = arr[i];
        }

        for (int i = 0; i < length; i++) //тут ми додаємо ці потрібні значення values[i]
            newArr[index + i] = values[i];

        for (int i = index + length; i < size + length; i++) //додаємо значення які залилшилися
            newArr[i] = arr[i - length];

        delete[] arr;
        arr = newArr;
        size += length;
    }

    void erase(int index, int n)
    {
        T* newArr = new T[capacity];

        for (int i = 0; i < index; i++)
            newArr[i] = arr[i];

        for (int i = index + n; i < size; i++)
            newArr[i - n] = arr[i];
        
        delete[] arr;
        arr = newArr;
        size -= n;
    }

    int getSize() {
        return size;
    }
    int getCapacity() {
        return capacity;
    }

    int get(int index) {
        return arr[index];
    }
    void set(int index, T value) {
        arr[index] = value;
    }
    

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main()
{
    int q;
    cin >> q;
    DynamicArray<int> myArr;

    for (int i = 0; i < q; i++)
    {
        string input;
        cin >> input;

        if (input == "size")
            cout << myArr.getSize() << endl; 
        else if (input == "capacity")
            cout << myArr.getCapacity() << endl; 
        else if (input == "insert")
        {           
            int index, count;
            cin >> index >> count;
            int arr[count];

            for (int j = 0; j < count; j++)
                cin >> arr[j];
            
            myArr.insert(index, count, arr); 
        } 
        else if (input == "get")
        {
            int index;
            cin >> index;
            cout << myArr.get(index) << endl;
        } 
        else if (input == "set")
        {
            int index, value;
            cin >> index >> value;
            myArr.set(index, value);
        } 
        else if (input == "erase")
        {
            int index, count;
            cin >> index >> count;
            myArr.erase(index, count);
        } 
        else if (input == "print")
            myArr.print();
    } 
    return 0;
}