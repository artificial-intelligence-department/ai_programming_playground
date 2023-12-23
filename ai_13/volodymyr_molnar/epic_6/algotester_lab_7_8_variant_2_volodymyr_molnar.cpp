#include <iostream>
using namespace std;

class DynArr {
private:
    int* array;
    int currSize;
    int currCap;

    void resize(int newCapacity) {
        int* tempArray = new int[newCapacity];
        for (int i = 0; i < currSize; ++i) {
            tempArray[i] = array[i];
        }
        delete[] array;
        array = tempArray;
        currCap = newCapacity;
    }

public:
    DynArr() : array(nullptr), currSize(0), currCap(1) {
        array = new int[currCap];
    }

    ~DynArr() {
        delete[] array;
    }

    void insert(int index, int N, int* elements) {
        if (currSize + N >= currCap) {
            while (currSize + N >= currCap)
                currCap *= 2;
            resize(currCap);
        }
        for (int i = currSize - 1; i >= index; --i)
            array[i + N] = array[i];
        for (int i = 0; i < N; ++i) 
            array[index + i] = elements[i];


        currSize += N;
    }void erase(int index, int n) {
        for (int i = index; i < currSize - n; ++i)
            array[i] = array[i + n];
        currSize -= n;
    }
    int capacity() {
        return currCap;
    }
    int get(int index) {
        return array[index];
    }
    int size() {
        return currSize;
    }
    void set(int index, int value) {
        array[index] = value;
    }
    int& operator[](int index) {
        return array[index];
    }

    friend ostream& operator<<(ostream& os, const DynArr& darr) {
        for (int i = 0; i < darr.currSize; ++i)
            os << darr.array[i] << " ";
        return os;
    }
};

int main() {
    int Q;
    cin >> Q;

    DynArr dynArr;

    for (int i = 0; i < Q; ++i) {
        string queue;
        cin >> queue;
        if (queue == "insert") {
            int index, N;
            cin >> index >> N;
            int* elements = new int[N];
            for (int j = 0; j < N; ++j) {
                cin >> elements[j];
            }
            dynArr.insert(index, N, elements);
            delete[] elements;
        }
        else if (queue == "erase") {
            int index, n;
            cin >> index >> n;
            dynArr.erase(index, n);
        }
        else if (queue == "get") {
            int index;
            cin >> index;
            cout << dynArr.get(index) << endl;
        }
        else if (queue == "set") {
            int index, value;
            cin >> index >> value;
            dynArr.set(index, value);
        }
        else if (queue == "capacity") 
            cout << dynArr.capacity() << endl;

        else if (queue == "size")
            cout << dynArr.size() << endl;

        else if (queue == "print") 
            cout << dynArr << endl;
    }

    return 0;
}